#include <stdio.h>
#include <math.h>

struct array{
    int A[10];
    int length;
};

int BS_iterative (struct array a , int key)
{
    int low = 0 , high = (a.length) - 1 , middle;
    while (low <= high)
    {
        middle = floor((low + high) / 2);
        
        if (key == a.A[middle])
            return middle;
            
        else if (key < a.A[middle])
            high = middle -1;
            
        else low = middle + 1;
    }
    return -1;
}

int BS_recursive (struct array a , int key, int low , int high)
{
    if (low <= high){
        int middle = floor((low + high) / 2);
        
        if (key == a.A[middle]) 
            return middle;
            
        else if (key < a.A[middle])
            return BS_recursive (a, key , low , middle -1);
        
        else
            return BS_recursive (a, key , middle + 1 , high);
    }
    return -1;
    
}