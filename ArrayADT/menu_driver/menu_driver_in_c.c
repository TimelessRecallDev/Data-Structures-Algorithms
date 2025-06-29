#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements are:\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
    else
        printf("Array is full");
}

void Insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length && arr->length < arr->size) {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    } else {
        printf("Invalid index\n");
    }
}

int Delete(struct Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    printf("Invalid index\n");
    return 0;
}

int linear_search(struct Array a, int key) {
    for (int i = 0; i < a.length; i++) {
        if (a.A[i] == key)
            return i;
    }
    return -1;
}

int BS_iterative(struct Array a, int key) {
    int low = 0, high = a.length - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (key == a.A[middle])
            return middle;
        else if (key < a.A[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int BS_recursive(struct Array a, int key, int low, int high) {
    if (low <= high) {
        int middle = (low + high) / 2;
        if (key == a.A[middle])
            return middle;
        else if (key < a.A[middle])
            return BS_recursive(a, key, low, middle - 1);
        else
            return BS_recursive(a, key, middle + 1, high);
    }
    return -1;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get_max(struct Array a) {
    int max = a.A[0];
    for (int i = 1; i < a.length; i++) {
        if (a.A[i] > max)
            max = a.A[i];
    }
    return max;
}

int get_min(struct Array a) {
    int min = a.A[0];
    for (int i = 1; i < a.length; i++) {
        if (a.A[i] < min)
            min = a.A[i];
    }
    return min;
}

int sum(struct Array a) {
    int s = 0;
    for (int i = 0; i < a.length; i++) {
        s += a.A[i];
    }
    return s;
}

int average(struct Array a) {
    if (a.length == 0) return 0; 
    return sum(a) / a.length;
}

void m1_auxiliary_array(struct Array *a) {
    int B[10];
    for (int i = a->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = a->A[i];
    }
    for (int i = 0; i < a->length; i++) {
        a->A[i] = B[i];
    }
}

void m2_interchanging_elements(struct Array *a) {
    int i = 0, j = a->length - 1;
    while (i < j) {
        swap(&a->A[i], &a->A[j]);
        i++;
        j--;
    }
}

void insert_sorted(struct Array *a, int x) {
    if (a->length >= a->size) {
        printf("Array is full");
        return;
    }
    int i = a->length - 1;
    while (i >= 0 && a->A[i] > x) {
        a->A[i + 1] = a->A[i];
        i--;
    }
    a->A[i + 1] = x;
    a->length++;
}

bool is_sorted(struct Array *a) {
    for (int i = 0; i < a->length - 1; i++) {
        if (a->A[i] > a->A[i + 1])
            return false;
    }
    return true;
}

void rearrange(struct Array *a) {
    int i = 0, j = a->length - 1;
    while (i < j) {
        while (i < j && a->A[i] < 0) i++;
        while (i < j && a->A[j] >= 0) j--;
        if (i < j) {
            swap(&a->A[i], &a->A[j]);
        }
    }
}

struct Array* merge_array(struct Array *a, struct Array *b) {
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    if (!c) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    c->size = 10;
    c->length = 0;

    int i = 0, j = 0;
    while (i < a->length && j < b->length) {
        if (a->A[i] < b->A[j])
            c->A[c->length++] = a->A[i++];
        else
            c->A[c->length++] = b->A[j++];
    }
    while (i < a->length)
        c->A[c->length++] = a->A[i++];
    while (j < b->length)
        c->A[c->length++] = b->A[j++];

    return c;
}

struct Array* difference(struct Array *arr1, struct Array *arr2) {
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (!arr3) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    arr3->size = 10;
    int i = 0, j = 0, k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    arr3->length = k;
    return arr3;
}

struct Array* set_union(struct Array *arr1, struct Array *arr2) {
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (!arr3) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    arr3->size = 10;
    int i = 0, j = 0, k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];
    arr3->length = k;
    return arr3;
}

struct Array* intersection(struct Array *arr1, struct Array *arr2) {
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    if (!arr3) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    arr3->size = 10;
    int i = 0, j = 0, k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

int main() {
    struct Array arr = {{}, 10, 0};
    int choice, x, index;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display\n2. Append\n3. Insert\n4. Delete\n5. Linear Search\n");
        printf("6. Binary Search\n7. Max\n8. Min\n9. Sum\n10. Average\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Display(arr);
                break;
            case 2:
                printf("Enter element to append: ");
                scanf("%d", &x);
                Append(&arr, x);
                break;
            case 3:
                printf("Enter index and value: ");
                scanf("%d%d", &index, &x);
                Insert(&arr, index, x);
                break;
            case 4:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                printf("Deleted: %d\n", Delete(&arr, index));
                break;
            case 5:
                printf("Enter key to search: ");
                scanf("%d", &x);
                index = linear_search(arr, x);
                printf(index != -1 ? "Found at %d\n" : "Not found\n", index);
                break;
            case 6:
                printf("Enter key for binary search: ");
                scanf("%d", &x);
                index = BS_iterative(arr, x);
                printf(index != -1 ? "Found at %d\n" : "Not found\n", index);
                break;
            case 7:
                printf("Max: %d\n", get_max(arr));
                break;
            case 8:
                printf("Min: %d\n", get_min(arr));
                break;
            case 9:
                printf("Sum: %d\n", sum(arr));
                break;
            case 10:
                printf("Average: %d\n", average(arr));
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}