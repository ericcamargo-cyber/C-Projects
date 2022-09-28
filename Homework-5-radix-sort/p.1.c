#include <stdio.h>
#include <stdlib.h>
const int SIZE=100;

int find_max(int nums[], int n) {
	int i;
	int max = nums[0];
	for(i=1; i < n; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
	
}

void count_sort(int nums[], int n, int exp) {
	int output[n];
	int i, x[100] = { 0 };
	
	for (i=0; i< n ; i++) {
		
		x[(nums[i]/exp) % 10]++;
	}
	
	for (i = 1; i < 10; i++) {
	
        x[i] += x[i - 1];
	}
    
    for (i = n - 1; i >= 0; i--) {
    	
        output[x[(nums[i] / exp) % 10] - 1] = nums[i];
        x[(nums[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++) {
	
        nums[i] = output[i];
	}
	
}
void radix_sort(int nums[], int n) {
	int exp;
	int max = find_max(nums, n);
	for (exp = 1; max/exp > 0; exp *= 10) {
		count_sort(nums, n, exp);
	}
}
		
void print(int nums[], int n) {
	int i;
	for (i=0; i < n; i++) {
		printf("%d", nums[i]);
	}
	
}	
	


int main() {
	
	int count, i, n;
	printf("First enter the amount of numbers to be entered: \n");
	scanf("%d", &count);
	unsigned int nums[count];
	
	printf("Now enter each number one by one: \n");
	for(i=0 ; i<count; i++) {
		scanf("%lu", &nums[i]);	
		printf("\n ");
	}
	 n = sizeof(nums) / sizeof(nums[0]);
	radix_sort(nums, n);
	print(nums, n);
	return 0;
}
