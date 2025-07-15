#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* create (int arr[], int size){
    struct node *head =  (struct node *)malloc(sizeof(struct node));
    head-> data = arr[0];
    head-> next = NULL;
    
    struct node *temp = head;
    struct node *last;

    for (int i = 1 ; i < size ; i++){
        last = (struct node*) malloc(sizeof(struct node));
        last-> data = arr[i];
        last-> next = NULL;
        temp-> next = last;
        temp = last; 
    }

    return head;
}
int main(){

    int arr[] = {1,2,3,4,5};

    struct node* head = create ( arr, 5);

}