#include <stdio.h>
#include <stdlib.h>
struct node {

    int data;
    struct node *next;
    
};

struct node *head;

void insert(int item) {

    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
    
        printf("\nSTACK OVERFLOW");
        
    }
    
    else {

        ptr->data = item;
        if (head == NULL) {
        
            ptr->next = NULL;
            head = ptr;
        }
        
        else {
        
            temp = head;
            while (temp->next != NULL) {
            
                temp = temp->next;
                
            }
            
            temp->next = ptr;
            ptr->next = NULL;
            
        }
    }
}

void display() {

    struct node *ptr;
    ptr = head;
    if (ptr == NULL) {
    
        printf("No values to print");
        
    }
    
    else {
    
        printf("\nPrinting values: \n");
        
        while (ptr != NULL) {
        
            printf("%d ", ptr->data);
            ptr = ptr->next;
            
        }
    }
}
void displayRev(struct node *head) {

    if (head == NULL) {
    
        return;
        
    }  
    displayRev(head->next);
    printf("%d ", head->data);
    
}

void main() {

    int choice = 0;
    int num;
    printf("insert values, CTRL+D to end: \n");
    while (1) {

        if (scanf("%d", &num) == EOF) {
        
            break;
            
        }
        
        else {
        
            insert(num);
            
        }
    }
    
    display();
    printf("\nValues in reverse: \n");
    displayRev(head);
    
}