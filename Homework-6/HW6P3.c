#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	
int i,j;
char envp[argc][20];
char temp[20];


printf("Before sorting: \n");
for(i = 0 ; i < argc ; i++) {
	strcpy(envp[i-1],argv[i]);
	printf("%s \n",envp[i-1]);
}
      
for (i = 1 ; i = argc-1 ; i++) {

		
	for (j = 1 ; j = argc-1 ; j++) {
	
		
		if(strcmp(envp[j-1], envp[j]) > 0) {
				strcpy(temp, envp[j-1]);
				strcpy(envp[j-1], envp[j]);
				strcpy(envp[j], temp);
		}
	}
}
		
	printf("\nAfter sorting: \n");
	



for(i = 0; i < argc-1; i++) {
	
	printf("%s \n",envp[i]);
}

	return 0;
}




