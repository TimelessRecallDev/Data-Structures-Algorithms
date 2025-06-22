#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void display (struct Array arr)
{
    printf ("All the elements : \n");
    for (int i = 0 ; i < arr.length ; i++)
    {
        printf ("%d ", arr.A[i]);
    }
}
int main()
{
    struct Array arr;
    
    printf("Enter the size of array : ");
    scanf ("%d", &arr.size);
    
     arr.A = (int *)malloc(arr.size * sizeof (int));
    
    printf("How many numbers: ");
    scanf ("%d" , &arr.length);
    
    printf("Enter all the elements : \n");
    for (int i = 0 ;  i < arr.length ; i++)
    {
        scanf ("%d ", &arr.A[i]);
    }
    display(arr);
    
    //after using free(arr.A);
    //arr.A = NULL;
    
    return 0;
}