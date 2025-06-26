#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int *p  = (int *)malloc(sizeof (int) * 5);
    
    int *q = (int *)malloc(sizeof(int) * 10); //new dynamic array with larger size
    p[0] = 10; p[1] = 20; p[2] = 30; p[3] = 40; p[4] = 50; 
    
    for (int i = 0 ; i < 5 ; i++)
    {
        q[i] = p[i];  //copying all the elements in array pointed by q
    }
    
    free(p);
    
    p = q;   //assigning address of q to p
    
    q = NULL;
    
    for (int i = 0;  i < 5 ; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}