#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	unsigned long int num;
	int bit1, bit2, i;
	printf("Enter an integer: \n");
	scanf("%lu", &num);
	printf("Now enter bit 1 and bit 2 to print a range of the new binary number: \n");
	scanf("%d%d", &bit1, &bit2);
	
	for(i = 0; i<=31 ; i++) {
		int temp;
		if(i < bit1 || i > bit2) {
			temp = 1 << i;
			if((temp&num)!=0) {
				num = num&(~temp);
			}
		}
	}
	printf("\nThe num of the new range of bits is: %lu",num>>bit1);
	return 0;
}
