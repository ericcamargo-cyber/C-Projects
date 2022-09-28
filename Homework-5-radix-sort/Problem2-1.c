#include <stdio.h>
#include <stdlib.h>
const int SIZE=100;

int find_max(int p[], int n) {
	int i;
	int max = p[0];
	for(i=1; i < n; i++) {
		if (p[i] > max) {
			max = p[i];
		}
	}
	return max;
	
}

void count_sort(int p[], int n, int exp) {
	int output[n];
	int x[100] = { 0 };
	int i;
	
	for (i=0; i < n ; i++) {
		
		x[(p[i]/exp) % 10]++;
	}
	
	for (i = 1; i < 10; i++) {
	
        x[i] += x[i - 1];
	}
    
    for (i = n - 1; i >= 0; i--) {
    	
        output[x[(p[i] / exp) % 10] - 1] = p[i];
        x[(p[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++) {
	
        p[i] = output[i];
	}
	
}
void radix_sort(int p[], int n) {
	int exp;
	int max = find_max(p, n);
	for (exp = 1; max/exp > 0; exp *= 10) {
		count_sort(p, n, exp);
	}
}
		
void print(int p[], int n) {
	int i;
	for (i=0; i < n; i++) {
		printf("\n%d", p[i]);
	}
	
}	
	


int main() {
   
	int count, i, n;
	float nums[count]; 
	unsigned int *p = (unsigned int *) nums; 
	printf("First enter the amount of numbers to be entered: \n");
	scanf("%d", &count);
	
	
	printf("Now enter each number one by one: \n");
	for(i=0 ; i<count; i++) {
		scanf("%lu", &nums[i]);	
		printf("\n");
	}

	n = sizeof(nums) / sizeof(nums[0]);
	radix_sort(p, n);

	print(p, n);

	return 0;
}
