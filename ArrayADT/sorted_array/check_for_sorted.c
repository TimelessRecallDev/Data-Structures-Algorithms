#include <stdio.h>
#include <stdbool.h>

struct array{
    int A[10];
    int size;
    int length;
};

bool sorted(struct array *a){
    for (int i = 0 ; i < a->length - 1; i++){
        if (a->A[i] > a->A[i + 1])
            return false;
    }
    return true;
}

void display (struct array a){
    for (int i = 0 ; i < a.length ; i++)
        printf("%d ", a.A[i]);
        
    printf("\n");
}

int main(){
    struct array a ={{2,3,4,5,6}, 10, 5};
    
    display (a);
    
    printf("%d", sorted(&a));   //1 means sorted 

}