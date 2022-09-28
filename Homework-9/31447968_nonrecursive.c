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

#define MAX_FILES       10000
#define MAX_FILENAME    512
void monitorFile(char *fileName );
enum { FALSE, TRUE };

//struct stuff 😁
struct  statStruct {
    char fileName[MAX_FILENAME];  // File name
    struct  stat  status;   // Information from stat()
};

//🌍 variables
char*  fileNames[MAX_FILES];
int fileCount=0;
struct statStruct  stats[MAX_FILES];

char* DirNames[MAX_FILES];
struct statStruct  TempDir[MAX_FILES];
int DirCounter = 0;
int CurIndexDir = 0;
int CurIndexTemp = 0;
int LastIndexTemp = 0;
char* filetemp;


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

void processDirectory(char *dirName) {
		struct stat statBuf;
		mode_t mode;
		int result;
		int charsRead;
		DIR *dir;
		struct dirent *dirEntry;
		char fileName[MAX_FILENAME];
		dir=opendir(dirName);

		while( TRUE ) {
				dirEntry = readdir(dir);
		    if ( dirEntry == NULL ) break;
		    if ( strcmp(dirEntry->d_name, ".") != 0 && strcmp( dirEntry->d_name, "..") != 0) {
		        sprintf( fileName, "%s/%s", dirName,
		        dirEntry->d_name );
		        result = lstat(fileName, &statBuf); //get file stats
		        if ( result == -1 ) { //cant get to file
		            fprintf( stderr, "Cannot stat %s \n", fileName );
		            return;
		        }
						mode = statBuf.st_mode;  //file mode
		        if ( S_ISDIR( mode ) ){ //if directory 📁
		    				strcpy( TempDir[CurIndexTemp].fileName, fileName);
				        //printf("1: %s\n",TempDir[CurIndexTemp].fileName);
				        CurIndexTemp++;
		        }
		        else if(S_ISREG(mode)) { //if file 📃
		            addEntry(fileName, &statBuf);
		        		fileCount++;
		        }
				}
		}
		closedir(dir);
}

//Iterative meth
void linear(char *fileName){
    DirNames[DirCounter] = fileName;
    while (DirNames[DirCounter] != NULL){
        //printf("Directory passed: %s\n",DirNames[DirCounter]);
        processDirectory(DirNames[DirCounter]);
        //add the new Dir to DirNames
        for(int i = LastIndexTemp; i<CurIndexTemp; i++){
            //find the next empty slot in DirName
            while(DirNames[CurIndexDir] != NULL){
                CurIndexDir++;
            }
            //"append" to DirNames 📌
            DirNames[CurIndexDir] = TempDir[i].fileName;
        }
        LastIndexTemp = CurIndexTemp;
        DirCounter++;
    }
}

int main( int argc, char *argv[]) {
  filetemp = (char*) malloc(30 * sizeof(int));
        linear(argv[1]);
        sortArray();
        printArray();
        return (0);
}
