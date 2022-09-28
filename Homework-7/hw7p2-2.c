#include<stdio.h> 
#include<stdlib.h> 
struct Node { 

  int data; 
  struct Node *next;
  
};

struct Node*insert(struct Node*start,int num); 
void bubble_sort(struct Node *start); 
void swap(struct Node *a, struct Node *b);
void printList(struct Node *start); 

int main() {

  int i,num,n=0;
  struct Node*start;
  start=(struct Node*)malloc(sizeof(struct Node));
  start->next=NULL;
  while(1) {

    printf("Enter node: ");
    while (1) {

      if (scanf("%d", &num) == EOF) {
        
        break;
            
      }
        
      else {
        
        insert(start, num);
            
      }
        
        
    }
    
      printf("\n Linked list before sorting "); 
      printList(start); 
      bubble_sort(start);
      printf("\n Linked list after sorting "); 
      printList(start);  
      break;
        
	}
  
}

struct Node*insert(struct Node*start,int num) {

  struct Node*newNode;
  newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=num;
  newNode->next=start->next;
  start->next=newNode;
  return start;
        
}

void printList(struct Node *start) {

  struct Node *temp = start; 
  printf("\n"); 
  while (temp!=NULL) { 
        
    printf("%d ", temp->data); 
    temp = temp->next; 
                
  } 
} 

void bubble_sort(struct Node *start) {

  int temp, i; 
  struct Node *ptr1; 
  struct Node *lptr = NULL;
  if (start == NULL) {
  
    return;
    
  }

  do { 
    temp = 0; 
    ptr1 = start; 

    while (ptr1->next != lptr) { 
    
      if (ptr1->data > ptr1->next->data) {
       
        swap(ptr1, ptr1->next); 
        temp = 1; 
       } 
       ptr1 = ptr1->next; 
      } 
    lptr = ptr1; 
    } 
  while (temp); 
} 

void swap(struct Node *a, struct Node *b) { 

        int temp = a->data; 
        a->data = b->data; 
        b->data = temp; 
        
}