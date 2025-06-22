#include <stdio.h>

struct Arr{
    int A[10];
    int size;
    int length;
};

void Append (struct Arr *a, int x){
    if (a->size <= a-> length)
    {
        printf ("Error");
        return;
    }
    a-> A[a->length++] = x;
}

void display (struct Arr a)
{
    for (int i =0 ; i < a.length ; i++)
    {
        printf ("%d ", a.A[i]);
    }
}
void insert (struct Arr *a, int index , int x)
{
    if (index < 0 || index > a->length)
    {
        printf("Error");
        return;
    }
    for (int i = a->length ; i > index ; i--)
    {
        a->A[i] = a->A[i - 1];
    }
    a->A[index]= x;
    a->length++;
}

void delete_element(struct Arr *a ,int index) //for deleting the element
{
    if (index > a->length || index < 0) return;
    for (int i = index ; i < a->length - 1 ; i++)
    {
        a->A[i] = a->A[i + 1];
    }
    a->length--;
}
int main()
{
    struct Arr A = {{2,3,4,5,6},10,5};
    
    int x;
    
    printf("Enter the element: ");
    scanf("%d", &x);
    
    Append (&A, x);
    
    display (A);
    
    int element, index ;
    
    printf("\nEnter the element you want to insert & its index : ");
    scanf ("%d %d", &element, &index);
    
    insert (&A,index ,element);
    display (A);
    
    delete_element (A , 3);
    
}