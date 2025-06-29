#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

void rearrange(struct array *a){
    int i = 0 ;
    int j = a-> length -1;
    while (i < j){
        while (a->A[i] < 0) i++;
        while (a->A[j] > 0) j--;
        if (i < j){
            int temp = a->A[i];
            a->A[i] = a->A[j];
            a->A[j] = temp;
        }
    }
}

void display (struct array a){
    for (int i = 0 ; i < a.length ; i++)
        printf("%d ", a.A[i]);
        
    printf("\n");
}

int main(){
    struct array a ={{2,-3,4,-5,-6}, 10, 5};
    
    display (a);
    
    rearrange (&a);
    
    display (a);
}