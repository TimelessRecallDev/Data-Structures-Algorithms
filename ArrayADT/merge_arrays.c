#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int size;
    int length;
};

struct array * merge_array(struct array *a, struct array *b){
    struct array *c = (struct array *)malloc(sizeof(struct array));

    
    int i = 0, j = 0 , k =0;
    
    while (i < a->length && j < b->length){
        if (a->A[i] < b->A[j]) c->A[k++] = a->A[i++];
        else c->A[k++] = b->A[j++];
    }
    for ( ; i < a-> length ; i++) c->A[k++] = a->A[i];
    for ( ; j < b-> length ; j++) c->A[k++] = b->A[j];
    
    c->length = a->length + b-> length;
    c->size = 10;
    
    return c;
}

void display (struct array *a){
    for (int i = 0 ; i < a->length ; i++)
        printf("%d ", a->A[i]);
        
    printf("\n");
}

int main(){
    struct array a = {{3,8,16,20}, 10, 4};
    struct array b = {{4,10,12,22}, 10, 4};
    
    struct array *c = merge_array (&a, &b);

    display (c);
}