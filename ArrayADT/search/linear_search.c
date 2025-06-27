#include <stdio.h>

struct array
{
    int A[10];
    int length;
};
// Standard linear search
int linear_search(struct array a, int key)
{
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] == key)
        {
            return i;
        }
    }
    return -1; // Not found
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Improving linear search with Transposition
int ls_transposition(struct array *a, int key)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->A[i] == key){
            swap(&a->A[i], &a->A[i - 1]);
            return i - 1; 
        }
    }
    return -1; // Not found
}

// Improving linear search with Move to Front
int ls_movetofront(struct array *a, int key)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->A[i] == key)
        {
            swap(&a->A[0], &a->A[i]);
            return 0;
        }
    }
    return -1; // Not found
}

void display_array(struct array a) {
    printf("Array elements: ");
    for (int i = 0; i < a.length; i++) {
        printf("%d ", a.A[i]);
    }
    printf("\n");
}

int main()
{
    struct array arr_std = {{2, 3, 5, 6, 7, 8, 9}, 7};
    struct array arr_trans = {{2, 3, 5, 6, 7, 8, 9}, 7}; 
    struct array arr_mtf = {{2, 3, 5, 6, 7, 8, 9}, 7};
    int key;

    printf("Original array: ");
    display_array(arr_std);

    printf("Enter the element you want to search for: ");
    scanf("%d", &key);

    int result_std = linear_search(arr_std, key);
    printf("\n--- Standard Linear Search ---\n");
    printf("Element %d found at index (-1 if not found): %d\n", key, result_std);
    printf("Array after standard search (no change): ");
    display_array(arr_std);

    printf("\n--- Linear Search with Transposition ---\n");
    printf("Array before transposition search: ");
    display_array(arr_trans);
    int result_trans = ls_transposition(&arr_trans, key);
    printf("Element %d found at new index (-1 if not found): %d\n", key, result_trans);
    printf("Array after transposition: ");
    display_array(arr_trans);

    printf("\n--- Linear Search with Move to Front ---\n");
    printf("Array before move to front search: ");
    display_array(arr_mtf);
    int result_mtf = ls_movetofront(&arr_mtf, key);
    printf("Element %d found at new index (-1 if not found): %d\n", key, result_mtf);
    printf("Array after move to front: ");
    display_array(arr_mtf);

    return 0;
}