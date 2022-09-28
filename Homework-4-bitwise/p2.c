#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int num;
	int count=0, length=0,x=0,j=0;
	printf("Enter the number: \n");
	scanf("%d", &num);
	do {
		if(num%2==1) {
			count++;
		}
		else {
			if (length < count) {
				length = count;	
				x=j;
			}
			count=0;
		}
		num/=2;
		j++;
	} while(num>0);
	if (length < count) {
		length=count;
		x=j;
	}
	printf("The %d 1s are bit %d - bit %d", length,x-length,x-1);
	return 0;
	
}

