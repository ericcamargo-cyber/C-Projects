#include <stdio.h>
#include <string.h>

int main() {
	char string[127];
	printf("Enter the string to convert: \n");
	scanf("%s",&string);
	int i = 1;
	while(i <= 4)
	{
		if(string[strlen(string)-i]=='1') {
		
			string[strlen(string)-i]='0';
		}
		else {
		
			string[strlen(string)-i]='1';
			i++;
		}
	}
	printf("%s",string);
	return 0;
}
