#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

void insert_sorted(struct array *a, int x ){
    int i = a-> length -1;
    while (a->A[i] > x)
    {
        a->A[i + 1] = a->A[i];
        i--;
    }
    a->A[i+1] = x;
    a->length++;
}

void display (struct array a){
    for (int i = 0 ; i < a.length ; i++)
        printf("%d ", a.A[i]);
        
    printf("\n");
}

int main(){
    struct array a ={{2,3,4,5,6}, 10, 5};
    
    display (a);
    
    insert_sorted(&a,1);
    
    display (a);
}