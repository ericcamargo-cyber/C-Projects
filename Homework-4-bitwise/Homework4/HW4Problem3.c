#include <stdio.h>

int main() {
	char string[128];
  char ch;
	printf("Enter the string to convert: \n");
  scanf("%[^\n]s", string);
	int i = 0;
  for ( i=0; i<=127; i++) {
  
    if (string[i]!='\0') {
    
      ch=string[i]^0x0f;
      string[i]=ch;
      
    }
    else {
    
     break;
     
    }
  }
	printf("%s\n",string);
	return 0;
}
