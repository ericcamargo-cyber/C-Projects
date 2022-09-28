#include<stdio.h>

int m=0,num=4;
int calc_move(int temp[4][4],int goal_array[4][4]) {

	int i,j;
	int m=0;

	for(i=0;i < num;i++) {
		
		for(j=0;j < num;j++) {
			
			if(temp[i][j]!=goal_array[i][j]) {
				
				m++;
			}
			
		}
		
		
	}
	return m;	

}

int check_move(int input_array[4][4],int goal_array[4][4]) {

	int i,j;
	int y=1;
	for(i=0;i < num;i++) {
                	
    	for(j=0;j < num;j++) {
                    	
        	if(input_array[i][j]!=goal_array[i][j]) {
            	y=0;
			}
		}	
	}
	return y;

}



int main()

{

    int p,i,j;
	int num=4;
	int input_array[4][4],goal_array[4][4],temp[4][4],r[4][4];
	int m=0,x=0,y=0,d=1000;
	int d_min=0,k=0, o=0;
                
    goal_array[0][0]=1;
    goal_array[0][1]=2;
    goal_array[0][2]=3;
    goal_array[0][3]=4;
    goal_array[1][0]=5;
    goal_array[1][1]=6;
    goal_array[1][2]=7;
    goal_array[1][3]=8;
    goal_array[2][0]=9;
    goal_array[2][1]=10;
    goal_array[2][2]=11;
    goal_array[2][3]=12;
    goal_array[3][0]=13;
    goal_array[3][1]=14;
    goal_array[3][2]=15;
    goal_array[3][3]=0;
                
	printf("Goal State is: \n");

    for(i=0;i < num;i++) {
		for(j=0;j < num;j++) {
						
			printf("%d\t",goal_array[i][j]);
		}
		printf("\n");

                                                

    }

    printf("Enter the tile matrix to solve, one tile at a time: \n");

    for(i=0;i < num;i++) {
                	
        for(j=0;j < num;j++) {
            scanf("%d",&input_array[i][j]);
                		
		}
	}

    printf("Tile Matrix: \n");

    for(i=0;i < num;i++) {

        for(j=0;j < num;j++) {
                    	
            printf("%d\t",input_array[i][j]);
                    	
		}
		printf("\n");

    }

                

    while(!(check_move(input_array,goal_array))) {
				
                                k++;

                                d=1000;

                                for(i=0;i < num;i++)

                                                for(j=0;j < num;j++) {

                                                                if(input_array[i][j]==0) {

                                                                                x=i;
																				y=j;

                                                                }

                                                }
//move up

                                for(i=0;i < num;i++) {
                                	
                                	for(j=0;j < num;j++) {
									 
                                		temp[i][j]=input_array[i][j];
                                    }
                                	
								}
                        		if(x!=0) {

                                                p=temp[x][y];
												temp[x][y]=temp[x-1][y];
												temp[x-1][y]=p;

                                }

                                m=calc_move(temp,goal_array);
								d_min=k+m;
								if(d_min < d) {

                                                d=d_min;

                                                for(i=0;i < num;i++) {
                                                	
                                                	for(j=0;j < num;j++) {
                                                                	
                                                                	r[i][j]=temp[i][j];
                                                                	
																}
                                                	
												}
								}

//move down

                                for(i=0;i < num;i++) {
                                	
                                	for(j=0;j < num;j++) {
                                                	
                                                	temp[i][j]=input_array[i][j];
                                                	
												}
                                	
								}
								if(x!=num-1) {

                                                p=temp[x][y];
												temp[x][y]=temp[x+1][y];
												temp[x+1][y]=p;

                                }

                                m=calc_move(temp,goal_array);
								d_min=k+m;
								if(d_min < d) {

                                                d=d_min;
												for(i=0;i < num;i++) {
													
													for(j=0;j < num;j++) {
                                                                	
                                                                	r[i][j]=temp[i][j];
                                                                	
																}
													
												}
								}
//move right

                                for(i=0;i < num;i++) {
                                	
                                	for(j=0;j < num;j++) {
                                                	
                                                	temp[i][j]=input_array[i][j];
                                                	
												}
                                	
								}
								if(y!=num-1) {

                                                p=temp[x][y];
												temp[x][y]=temp[x][y+1];
												temp[x][y+1]=p;

                                }

                                m=calc_move(temp,goal_array);
								d_min=k+m;
								if(d_min < d) {

                                                d=d_min;

                                                for(i=0;i < num;i++) {
                                                	
                                                	for(j=0;j < num;j++) {
                                                                	
                                                                	r[i][j]=temp[i][j];
                                                                	
																}
                                                	
												}
								}

//move left

                                for(i=0;i < num;i++) {
                                	
                                	for(j=0;j < num;j++) {
                                                	
                                                	temp[i][j]=input_array[i][j];
                                                	
												}
                                	
								}
								if(y!=0) {

                                                p=temp[x][y];
												temp[x][y]=temp[x][y-1];
												temp[x][y-1]=p;

                                }
								m=calc_move(temp,goal_array);
								d_min=k+m;
								if(d_min < d) {

                                                d=d_min;

                                                for(i=0;i < num;i++) {
                                                	
                                                	for(j=0;j < num;j++) {
                                                                	
                                                                	r[i][j]=temp[i][j];
                                                                	
																}
                                                	
												}
								}
								printf("Matrix next iteration: \n");

                                for(i=0;i < num;i++) {

                                                for(j=0;j < num;j++)

                                                printf("%d\t",r[i][j]);

                                                printf("\n");

                                }

                                for(i=0;i < num;i++)

                                                for(j=0;j < num;j++) {

                                                input_array[i][j]=r[i][j];
												temp[i][j]=0;

                                                }

                                
                                if (o == 50) {
                                	printf("\n ERROR, NO SOLUTION FOUND");
                                	break;
								}
                                o++;

                }
                

                

}
}
