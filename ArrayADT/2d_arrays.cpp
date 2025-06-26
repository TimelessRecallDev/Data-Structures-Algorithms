#include <iostream>
using namespace std;

int main()
{
    //Method- 1 {Everything will be in stack}
    
    int A[3][4] = {{1,2,3,4}, {2,5,6}, {6,7,8}};
    
    //Method- 2 {Partial in heap}
    
    int *A[3];
    
    A[0] = new int [4];
    A[1] = new int [4];
    A[2] = new int [4];
    
    //Method - 3 {Everything will be in heap}
    
    int **A; //Note : double pointer will be in stack
    
    A = new int *[3];
    A[0] = new int [4];
    A[1] = new int [4]; 
    A[2] = new int [4];
    
    //for accessing the 2d array just use nested for loop
    
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            //access
        }
    }
}

