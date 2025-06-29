#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

struct Array* intersection(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    
    int i =0 , j= 0 , k =0;
    
    while (i < arr1->length && j < arr2-> length)
    {
        if (arr1->A[i] < arr2 ->A[j]) i++;
        else if (arr2 -> A[j] < arr1 -> A[i]) j++;
        else {
            arr3 -> A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3-> length= k;
    
    return arr3;
}
void display (struct Array *a){
    for (int i = 0 ; i < a-> length ; i++)
        printf("%d ", a->A[i]);
}
int main(){
    struct Array arr1 = {{3,4,5,6,8}, 10 ,5};
    struct Array arr2 = {{3,4,7,9,10}, 10 ,5};
    
    struct Array *arr3 = intersection(&arr1, &arr2);
    
    display(arr3);
}