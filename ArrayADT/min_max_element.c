#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

int get_max (struct array a){
    int max = a.A[0];
    
    for (int i = 0; i < a.length ; i++)
    {
        if (a.A[i] > max) max = a.A[i];
    }
    return max;
}

int get_min (struct array a){
    int min = a.A[0];
    
    for (int i = 0 ; i < a.length ; i++){
        if (a.A[i] < min) min = a.A[i];
    }
    return min;
}

int main()
{
    struct array a ={{2,3,4,5,6}, 10, 5};
    
    printf ("Max Element : %d & Min Element : %d " ,get_max(a), get_min (a));

}