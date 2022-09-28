#include <stdio.h>

int main() {
	
	char string[128];
  int length = 0;
	int count = 0 , i, j;
	printf("Enter a string: \n");
	scanf("%[^\n]",string);
  while (string[length]) {
    length++;
  }
  
	for (i=0 ; i<length ; i++) {
 
    for (j=0; j<8; j++) {
    
      if((string[i]&(1<<j))== 0) {
			count++;
      }
	
		}
		
	}
	printf("The count of 0s is %d\n", count);
	return 0;	
}
