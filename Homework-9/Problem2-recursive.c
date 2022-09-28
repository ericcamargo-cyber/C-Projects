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
#define MAX_file_name	512

void monitor_file(char *file_name );
enum { FALSE, TRUE };

struct  status_struct {

	char file_name[MAX_file_name];
	struct  stat  status;
 
};

char*  file_names[MAX_FILES];
int file_count = 0;
struct status_struct  stats[MAX_FILES];

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

void process_directory(char *directory_name) {

		int char_read;
	  DIR *dir;
		struct dirent *directory_entry;
		char file_name[MAX_file_name];
    dir=opendir(directory_name);
		while( TRUE ) {
   
				directory_entry = readdir(dir);
				if ( directory_entry == NULL ) break;
				if ( strcmp(directory_entry->d_name, ".") != 0 && strcmp( directory_entry->d_name, "..") != 0) {
        
						sprintf( file_name, "%s/%s", directory_name, directory_entry->d_name );
						monitor_file( file_name );
                                    
				}
		}
		closedir(dir);
}

void monitor_file(char *file_name ) {

		struct stat statBuf;
		mode_t mode;
		int result;
    result = lstat(file_name, &statBuf);
		if ( result == -1 ) {
   
				fprintf( stderr, "Cannot stat %s \n", file_name );
				return;
        
		}
		mode = statBuf.st_mode;
		if ( S_ISDIR( mode ) ) {
   
				process_directory( file_name );
        
		}
		else if(S_ISREG(mode)) {
   
				add_entry(file_name, &statBuf);
				file_count++;
        
		}
   
}

int main( int argc, char *argv[]) {

		monitor_file(argv[1]);
		sort_array();
		print_array();
		return (0);
   
}
