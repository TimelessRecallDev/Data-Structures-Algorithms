#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

int sum (struct array a){
    int sum = 0;
    
    for (int i = 0 ; i < a.length ; i++){
        sum += a.A[i];
    }
    
    return sum;
}

int average (struct array a){
    
    return sum(a) / a.length;
    
}

int main()
{
    struct array a ={{2,3,4,5,6}, 10, 5};
    
    printf ("Sum of all the elements : %d and average : %d ", sum(a), average(a));
    


}