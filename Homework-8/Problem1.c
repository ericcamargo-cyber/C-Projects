#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define NxN (N*N)
#define TRUE 1
#define FALSE 0


struct node {
	int tiles[N][N];
	int f, g, h;
	short zero_row, zero_column;
	struct node *next;
	struct node *parent;
};

int goal_rows[NxN];
int goal_columns[NxN];
struct node *start,*goal;
struct node *open = NULL, *closed = NULL;
struct node *nex_nodes[4];

void print_a_node(struct node *pnode) {

	int i,j;
	for (i=0;i<N;i++) {
 
    for (j=0;j<N;j++) {
   
      printf("%2d ", pnode->tiles[i][j]);
      
    }
    
		printf("\n");
   
	}
 
	printf("\n");
 
}

struct node *initialize(char **argv) {

	int i,j,k,index, tile;
	struct node *pnode;
    char *p;
	pnode=(struct node *) malloc(sizeof(struct node));
	index = 1;
  for (j=0;j<N;j++) {
 
    for (k=0;k<N;k++) {
   
			tile=strtol(argv[index], &p,10);//this is where gdb is saying the error is originating from
      index++; 
			pnode->tiles[j][k]=tile;
      
      if(tile==0) {
      
				pnode->zero_row=j;
				pnode->zero_column=k;
        
      }
      
    }
   
  }
	pnode->f=0;
	pnode->g=0;
	pnode->h=0;
	pnode->next=NULL;
	pnode->parent=NULL;
	start=pnode;
	printf("initial state\n");
	print_a_node(start);

	pnode=(struct node *) malloc(sizeof(struct node));
	goal_rows[0]=3;
	goal_columns[0]=3;

	for(index=1; index<NxN; index++) {
 
		j=(index-1)/N;
		k=(index-1)%N;
		goal_rows[index]=j;
		goal_columns[index]=k;
		pnode->tiles[j][k]=index;
   
	}
 
	pnode->tiles[N-1][N-1]=0;
	pnode->f=0;
	pnode->g=0;
	pnode->h=0;
	pnode->next=NULL;
	goal=pnode; 
	printf("goal state\n");
	print_a_node(goal);

	return start;
}

void merge_to_open() {

	struct node *temp;
  struct node *current;
  struct node *n_node;
  for (int i=0;i<4;i++) {
  
		current = open;
    temp = open;

    if (nex_nodes[i] != NULL) {
    
            n_node=(struct node *) malloc(sizeof(struct node));
            for(int j = 0; j < N; j++) {
            
                for(int k = 0; k < N; k++) {
                
                    n_node->tiles[j][k]=nex_nodes[i]->tiles[j][k];
                    
                }
            }
            n_node->zero_row = nex_nodes[i]->zero_row;
            n_node->zero_column = nex_nodes[i]->zero_column;
            n_node->parent = nex_nodes[i]->parent;
            n_node->f = nex_nodes[i]->f;
            n_node->g = nex_nodes[i]->g;
            n_node->h = nex_nodes[i]->h;
            if (current == NULL) {
            
                open = n_node;
                
            } 
            else if (n_node->f <= current->f) {
            
                if (n_node->h <= current->h) {
                
                    n_node->next = current;
                    open = n_node;
                }
                
                else {
                
                    while (TRUE) {
                    
                        temp = current;
                        current = current->next;
                        if (current == NULL) {
                        
                            temp->next = n_node;
                            n_node->next = NULL;
                            break;
                        }
                        if (n_node->h <= current->h) {
                        
                            n_node->next = current;
                            temp->next = n_node;
                            break;
                        }
                        
                    }
                    
                }
                
            }
            
            else {
            
            while (TRUE) {
            
                temp = current;
                current = current->next;
                if (current == NULL) {
                
                    temp->next = n_node;
                    n_node->next = NULL;
                    break;
                    }
                    
                    if (n_node->f <= current->f) {
                    
                        n_node->next = current;
                        temp->next = n_node;
                        break;
                    }
                    
                }
                
            }
            
        }
        
    }
    
}


void swap(int row1,int column1,int row2,int column2, struct node * pnode) {

	int temp;
	temp = pnode->tiles[row1][column1];
    pnode->tiles[row1][column1] = pnode->tiles[row2][column2];
	pnode->tiles[row2][column2] = temp;
 
}

int manhattan(struct node * pnode) {

  int sum = 0;

  int ourValue = 0;

  int fbool = 0;
  for (int i = 0; i < N; i++) {

    for (int j = 0; j < N; j++) {
    
      ourValue = pnode->tiles[i][j];
      fbool = 0;
      for (int m = 0; m < N; m++) {
        
        for (int n = 0; n < N; n++) {
        
          if (ourValue == goal->tiles[m][n]) {
            
            sum += (abs(i - m) + abs(j - n));
            fbool = 1;
            break;

          }

        }

        if (fbool) {

          break;

        }

      }
    }

  }
return sum;

}

void update_fgh(struct node *pnode) {

  pnode->h = manhattan(pnode);
  pnode->g = pnode->parent->g+1;
  pnode->f = pnode->g + pnode->h;

}

void move_down(struct node * pnode) {

	if(pnode->zero_row+1 < N) {

    swap(pnode->zero_row, pnode->zero_column, pnode->zero_row+1, pnode->zero_column, pnode);
    pnode->zero_row++;
    
  }
  
	else {
 
    pnode = NULL;
    
    }
    
}


void move_right(struct node * pnode) {

	if(pnode->zero_column+1 < N) {
 
    swap(pnode->zero_row, pnode->zero_column, pnode->zero_row, pnode->zero_column+1, pnode);
    pnode->zero_column++;
        
  }
    
	else {
 
    pnode = NULL;
        
  }
    
}


void move_up(struct node * pnode) {

	if(pnode->zero_row-1 > -1) {
 
    swap(pnode->zero_row, pnode->zero_column, pnode->zero_row-1, pnode->zero_column, pnode);
    pnode->zero_row--;
  }
	else {
 
    pnode = NULL;
        
  }
    
}


void move_left(struct node * pnode) {

  if(pnode->zero_column-1 > -1) {
  
    swap(pnode->zero_row, pnode->zero_column, pnode->zero_row, pnode->zero_column - 1, pnode);
    pnode->zero_column--;
    
  }
    
	else {
 
    pnode = NULL;
    
  }
  
}

void expand(struct node *selected) {

  for(int i = 0; i < N; i++) {
    
    nex_nodes[i]=NULL;
   
  }
   
  int j = selected->zero_row;
  int k = selected->zero_column;
  move_down(nex_nodes[0]);
  move_right(nex_nodes[1]);
  move_up(nex_nodes[2]);
  move_left(nex_nodes[3]);
  for(int i = 0; i < N; i++){
  
    update_fgh(nex_nodes[i]);
        
  }
  
}

int nodes_same(struct node *a,struct node *b) {

	int flg=FALSE;
	if (memcmp(a->tiles, b->tiles, sizeof(int)*NxN) == 0) {
 
		flg=TRUE;
   
  }
  
  return flg;
  
}


void filter(int i, struct node *pnode_list) { 

	struct node *temp;
	temp = pnode_list;
  if (nex_nodes[i] != NULL) {
  
		while (temp != NULL) {
   
			if (nodes_same(nex_nodes[i], temp)) {
      
				if (nex_nodes[i]->f >= temp->f) {
        
					nex_nodes[i] = NULL;
					break;
                
        }
        
      }
      
			temp = temp->next;
      
		}
   
	}
 
}


int main(int argc,char **argv) {

	int iter,cnt;
	struct node *copen, *cp, *solution_path;
	int ret, i, pathlen=0, index[N-1];
  solution_path=NULL;
	start=initialize(argv);	 //gdb also shows this line as a reason for the segmentation fault, using the initialize function
	open=initialize(argv); 
  iter=0; 
	while (open!=NULL) {
  	
		copen=open;
		open=open->next;  
		if(nodes_same(copen,goal)) {

			do {
      
				copen->next=solution_path;
				solution_path=copen;
				copen=copen->parent;
				pathlen++;
        
			} while(copen!=NULL);
      
			printf("Path (lengh=%d):\n", pathlen); 
			copen=solution_path;
			break;
		}
		expand(copen);       
		for(i=0;i<4;i++) {
   
			filter(i,open);
			filter(i,closed);
      
		}
   
		merge_to_open();
		copen->next=closed;
		closed=copen;
		iter++;
		if(iter %1000 == 0) {
   
			printf("iter %d\n", iter);
      
    }
    
	}
 
	return 0;
 
}
