#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

void m2_interchanging_elements(struct array *a){
    
    for(int i = a->length -1 , j = 0 ; i > j  ; i--, j++){
        int  temp = a->A[i];
        a->A[i] = a->A[j];
        a->A[j] = temp;
    }
}

int main(){
    struct array a ={{2,3,4,5,6}, 10, 5};
    
   m2_interchanging_elements(&a);
    
    printf("Reversed Array:");
    
    for(int i = 0 ; i < a.length ; i++)
         printf (" %d ", a.A[i]);
   
}