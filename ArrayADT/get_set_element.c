#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

int get_element (struct array a, int index){
    if (index >= 0 && index < a.length)
        return a.A[index];
    return -1;
}

void set_element(struct array *a , int index, int x){
    if (index >= 0 && index < a->length)
        a->A[index] = x;
}

int main()
{
    struct array a ={{2,3,4,5,6}, 10, 5};

    printf ("%d\n", get_element(a, 3));

    set_element (&a, 3 , 20);

    printf ("%d\n", get_element (a, 3));

    return 0;
}