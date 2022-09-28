#include <stdio.h>
#include <string.h>

int main() {
	char string[127];
	int count = 0 , i;
	printf("Enter a string: \n");
	scanf("%s",string);
	for(i=0 ; i<strlen(string) ; i++) {
	
		if(string[i]=='0') {
			count++;
		}
		
	}
	printf("The count of 0s is %d", count);
	return 0;
	
}
