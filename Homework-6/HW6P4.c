#include<stdio.h>
#include<stdlib.h>

int main() {
  
int size;
int** tri, row, col;
  
printf("Enter the size: \n");
scanf("%d", &size);
   
tri = (int**)malloc(sizeof(int*)*(size+1));
tri[0] = (int*)malloc(sizeof(int));
tri[0][0] = 1;

for (row = 1; row <= size; row++) {
    
	tri[row] = (int*)malloc(sizeof(int)*(row+1));
    tri[row][0] = 1;
      
    if (row==1 && col==1) {
    	
    	tri[row][row] = 1; 
    	
	}
    
	for (col=1; col<row;col++) {
		
        tri[row][col] = tri[row-1][col-1] + tri[row-1][col];
        
    }
    
	tri[row][row-1] = 1;
	
}

int space = 0;
   
for(row = 0; row <=size; row++) {
   	
    for(space = size; space >= row ; space--) {

       	printf(" ");
       		
	}
	   
    for(col=0; col<row; col++) {
       	
        printf("%d ", tri[row][col]);
           
    }
       
    printf("\n");
       
       
}

}


