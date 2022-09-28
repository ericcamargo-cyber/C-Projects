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
#define MAX_file_name    512

void monitorFile(char *file_name );
enum { FALSE, TRUE };

struct  status_struct {

    char file_name[MAX_file_name];
    struct  stat  status;
    
};

char*  file_names[MAX_FILES];
int file_count=0;
struct status_struct  stats[MAX_FILES];
char* directory_names[MAX_FILES];
struct status_struct  TempDir[MAX_FILES];
int directory_count = 0;
int current_index_directory = 0;
int current_index_temp = 0;
int last_index_temp = 0;
char* filetemp;

void print_array() {

		long i;
   
		for(i=0; i<file_count; i++) {
   
        printf("%ld\t%s\n",stats[i].status.st_size,stats[i].file_name);
        
		}
   
}

void sort_array() {

		int i;
		int j;
		char temp[MAX_file_name];
		struct stat temp_status;
		for( i=0; i<file_count-1; i++) {
   
		    for( j=0; j<file_count-1-i; j++) {
            
		        if(stats[j].status.st_size>stats[j+1].status.st_size) {
                    
		            strcpy(temp,stats[j].file_name);
		            temp_status=stats[j].status;
		            strcpy(stats[j].file_name,stats[j+1].file_name);
		            stats[j].status=stats[j+1].status;
		            strcpy(stats[j+1].file_name,temp);
		            stats[j+1].status=temp_status;
                            
		        }
                    
		    }
            
		}
   
}

void add_entry(char *file_name,struct stat *statBuf ) {

		strcpy( stats[file_count].file_name, file_name);
		stats[file_count].status = *statBuf;
   
}

void process_directory(char *dirName) {

		struct stat statBuf;
		mode_t mode;
		int result;
		int charsRead;
		DIR *dir;
		struct dirent *dirEntry;
		char file_name[MAX_file_name];
		dir=opendir(dirName);

		while( TRUE ) {
   
				dirEntry = readdir(dir);
		    if ( dirEntry == NULL ) break;
		    if ( strcmp(dirEntry->d_name, ".") != 0 && strcmp( dirEntry->d_name, "..") != 0) {
		        sprintf( file_name, "%s/%s", dirName,
		        dirEntry->d_name );
		        result = lstat(file_name, &statBuf);
		        if ( result == -1 ) {
                    
		            fprintf( stderr, "Cannot stat %s \n", file_name );
		            return;
                            
		        }
                    
						mode = statBuf.st_mode;
		        if ( S_ISDIR( mode ) ) {
                    
		    				strcpy( TempDir[current_index_temp].file_name, file_name);
				        current_index_temp++;
                                                                
		        }
                    
		        else if(S_ISREG(mode)) {
                    
		            add_entry(file_name, &statBuf);
		        		file_count++;
                                   
		        }
                    
				}
        
		}
   
		closedir(dir);
   
}

void linear(char *file_name) {

    directory_names[directory_count] = file_name;
    while (directory_names[directory_count] != NULL) {
    
        process_directory(directory_names[directory_count]);
        for(int i = last_index_temp; i<current_index_temp; i++) {
        
            while(directory_names[current_index_directory] != NULL) {
            
                current_index_directory++;
                
            }
            
            directory_names[current_index_directory] = TempDir[i].file_name;
            
        }
        
        last_index_temp = current_index_temp;
        directory_count++;
        
    }
    
}

int main( int argc, char *argv[]) {

  filetemp = (char*) malloc(30 * sizeof(int));
  linear(argv[1]);
  sort_array();
  print_array();
  return (0);
  
}
