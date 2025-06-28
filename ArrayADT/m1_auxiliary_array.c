#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

void m1_auxiliary_array(struct array *a){
    int B[10];
    
    for(int i = a->length -1 , j = 0 ; i >= 0  ; i--, j++){
        B[j] = a->A[i];
    }
    for (int i = 0 ; i < a->length ; i++){
        a->A[i] = B[i];
    }
}

int main(){
    struct array a ={{2,3,4,5,6}, 10, 5};
    
    m1_auxiliary_array(&a);
    
    printf("Reversed Array:");
    
    for(int i = 0 ; i < a.length ; i++)
         printf (" %d ", a.A[i]);
   
}