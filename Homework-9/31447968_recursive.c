#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define MAX_FILES	10000
#define MAX_FILENAME	512
void monitorFile(char *fileName );
enum { FALSE, TRUE };

//struct stuff 😁
struct  statStruct {
	char fileName[MAX_FILENAME];
	struct  stat  status;
};
//🌍 variables
char*  fileNames[MAX_FILES];
int fileCount=0;
struct statStruct  stats[MAX_FILES];

void printArray(){
		long i;
		for(i=0; i<fileCount; i++){
				printf("%ld\t%s\n",stats[i].status.st_size,stats[i].fileName);
		}
}

void sortArray(){
		int i;
		int j;
		char temp[MAX_FILENAME];
		struct stat tempStatus;
		for( i=0; i<fileCount-1; i++){
				for( j=0; j<fileCount-1-i; j++){
						if(stats[j].status.st_size>stats[j+1].status.st_size){
								strcpy(temp,stats[j].fileName);
								tempStatus=stats[j].status;
								strcpy(stats[j].fileName,stats[j+1].fileName);
								stats[j].status=stats[j+1].status;
								strcpy(stats[j+1].fileName,temp);
								stats[j+1].status=tempStatus;
						}
				}
		}
}

void addEntry(char *fileName,struct stat *statBuf ){
		strcpy( stats[fileCount].fileName, fileName);
		stats[fileCount].status = *statBuf;
}

void processDirectory(char *dirName) {/*Process files in a directory*/
		int charsRead;
	  DIR *dir;
		struct dirent *dirEntry;
		char fileName[MAX_FILENAME];

    dir=opendir(dirName); /* Open for reading */
		while( TRUE ) { /* Read all directory entries */
				dirEntry = readdir(dir);
				if ( dirEntry == NULL ) break;  /* EOF */
				if ( strcmp(dirEntry->d_name, ".") != 0 && strcmp( dirEntry->d_name, "..") != 0) {
						sprintf( fileName, "%s/%s", dirName, dirEntry->d_name );
						monitorFile( fileName );
				}
		}
		closedir(dir);
}

void monitorFile(char *fileName ) {/* Process a file/directory */
		struct stat statBuf;
		mode_t mode;
		int result;

		result = lstat(fileName, &statBuf); /* Obtain file status */
		if ( result == -1 ) { /* Status was not available */
				fprintf( stderr, "Cannot stat %s \n", fileName );
				return;
		}
		mode = statBuf.st_mode;  /* Mode of file */
		if ( S_ISDIR( mode ) ){ /* Directory */
				processDirectory( fileName );
		}
		else if(S_ISREG(mode)) {
				addEntry(fileName, &statBuf);
				fileCount++;
		}
}

int main( int argc, char *argv[]) {
		monitorFile(argv[1]);
		sortArray();
		printArray();
		return (0);
}
