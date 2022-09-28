#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <time.h>

void radix_sort(unsigned int binList[], unsigned int binBuff[], int numOfFloats) {
  int i;
  int j;
  int radix = 8;
  int buckets = 1 << radix;
  int mask = buckets - 1;
  int rounds = 32 / radix;
  int flag = 0;
  int count[buckets];
  int map[buckets];
  unsigned int *source;
  unsigned int *dest;

  for (i = 0; i < sizeof(int) * CHAR_BIT; i = i + radix) {

    if (flag == 0) {
      source = binList;
      dest = binBuff;
    }
    else {
      source = binBuff;
      dest = binList;
    }

    for (j = 0; j < buckets; j++) {
      count[j] = 0;
      map[j] = 0;
    }

    for (j = 0; j < numOfFloats; j++) {
      count[source[j] >> i & mask]++;
    }

    for (j = 2; j < buckets; j++) {
      map[j] = map[j - 1] + count[j - 1];
    }

    for (j = 0; j < numOfFloats; j++) {
      dest[map[source[j] >> i & mask]++] = source[j];
    }

    if (flag == 0) {
      flag = 1;
    }
    else {
      flag = 0;
    }
  }
}

int main(int argc, char *argv[], char * envp[]){

  int file = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);

  if(file==-1){
      perror("Problem opening file.");
      exit(EXIT_FAILURE);
  }

  struct stat filestats;

  if(fstat(file,&filestats)==-1){
    perror("couldn't get file size.\n");
  }

  int numOfFloats = filestats.st_size/sizeof(float);


  float *fileMem = (float *)mmap(NULL,filestats.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file,0);

  if (fileMem == MAP_FAILED) {
      close(file);
      perror("Error mapping file\n");
      exit(EXIT_FAILURE);
  }

  unsigned int *binList = malloc(sizeof(unsigned int) * numOfFloats);
  unsigned int *binBuff = malloc(sizeof(unsigned int) * numOfFloats);
  printf("Original...\n\n");
  for (int i=0; i < numOfFloats; i++) {
      binList[i] = (unsigned int)(fileMem[i]);
  }

  radix_sort(binList, binBuff, numOfFloats);

  for (int i = 0; i < numOfFloats; i++){
			fileMem[i] = binList[i];
	}
  if (msync(fileMem, filestats.st_size, MS_SYNC) == -1){
    perror("Couldn't sync");
  }
  if (munmap(fileMem, filestats.st_size) == -1) {
      perror("Error un-mapping file");
  }
  close(file);
  free(binList);
  free(binBuff);
  return 0;
}
