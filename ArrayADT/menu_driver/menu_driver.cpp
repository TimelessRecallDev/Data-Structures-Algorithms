#include <iostream>
#include <cstdlib> // For exit

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
public:
    //constructor with no params
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }
    //constructor
    Array(int s) {
        size = s;
        length = 0;
        A = new int[size];
    }
    //destructor
    ~Array() {
        delete[] A;
    }
    //methods
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int linear_search(int key);
    int BS_iterative(int key);
    int BS_recursive(int key, int low, int high); 
    void swap(int *x, int *y);
    int get_max();
    int get_min();
    int sum();
    int average();
    void m1_auxiliary_array();
    void m2_interchanging_elements();
    void insert_sorted(int x);
    bool is_sorted();
    void rearrange();
    Array set_union(const Array &arr2);
    Array intersection(const Array &arr2);
    Array difference(const Array &arr2);
}; 

void Array::Display() {
    cout << "Elements are : ";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::Append(int x) {
    if (length < size)
        A[length++] = x;
    else
        cout << "Array is full\n"; 
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length && length < size) {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    } else {
        cout << "Invalid index\n"; 
    }
}

int Array::Delete(int index) {
    int x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    cout << "Invalid index\n"; 
    return 0;
}

int Array::linear_search(int key) {
    for (int i = 0; i < length; i++) {
        if (A[i] == key)
            return i;
    }
    return -1;
}

int Array::BS_iterative(int key) {
    int low = 0, high = length - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (key == A[middle])
            return middle;
        else if (key < A[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int Array::BS_recursive(int key, int low, int high) {
    if (low <= high) {
        int middle = (low + high) / 2;
        if (key == A[middle])
            return middle;
        else if (key < A[middle])
            return BS_recursive(key, low, middle - 1);
        else
            return BS_recursive(key, middle + 1, high);
    }
    return -1;
}

void Array::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::get_max() {
    if (length == 0) {
        cout << "Array is empty, no max element.\n";
        return -1; 
    }
    int max_val = A[0]; 
    for (int i = 1; i < length; i++) {
        if (A[i] > max_val)
            max_val = A[i];
    }
    return max_val;
}

int Array::get_min() {
    if (length == 0) {
        cout << "Array is empty, no min element.\n";
        return -1;
    }
    int min_val = A[0]; 
    for (int i = 1; i < length; i++) {
        if (A[i] < min_val)
            min_val = A[i];
    }
    return min_val;
}

int Array::sum() {
    int s = 0;
    for (int i = 0; i < length; i++) {
        s += A[i];
    }
    return s;
}

int Array::average() {
    if (length == 0) return 0;
    return sum() / length; 

void Array::m1_auxiliary_array() {

   
    int B[this->length]; 
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    for (int i = 0; i < length; i++) {
        A[i] = B[i];
    }
}

void Array::m2_interchanging_elements() {
    int i = 0, j = length - 1;
    while (i < j) {
        swap(&A[i], &A[j]);
        i++;
        j--;
    }
}

void Array::insert_sorted(int x) {
    if (length >= size) {
        cout << "Array is full\n";
        return;
    }
    int i = length - 1;
 
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

bool Array::is_sorted() {
    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

void Array::rearrange() {
    int i = 0, j = length - 1;
    while (i < j) {
        while (i < j && A[i] < 0) i++;
        while (i < j && A[j] >= 0) j--;
        if (i < j) {
            swap(&A[i], &A[j]);
        }
    }
}

Array Array::difference(const Array &arr2) {
    
    Array *arr3 = new Array(this->length + arr2.length); 
    int i = 0, j = 0, k = 0;

    while (i < this->length && j < arr2.length) {
        if (this->A[i] < arr2.A[j])
            arr3->A[k++] = this->A[i++];
        else if (arr2.A[j] < this->A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    while (i < this->length) 
        arr3->A[k++] = this->A[i++];

    arr3->length = k;
    Array result = *arr3; 
    delete arr3; 
    return result;
}

Array Array::set_union(const Array &arr2) {

    Array *arr3 = new Array(this->length + arr2.length);
    int i = 0, j = 0, k = 0;

    while (i < this->length && j < arr2.length) {
        if (this->A[i] < arr2.A[j])
            arr3->A[k++] = this->A[i++];
        else if (arr2.A[j] < this->A[i])
            arr3->A[k++] = arr2.A[j++];
        else { 
            arr3->A[k++] = this->A[i++];
            j++;
        }
    }
    while (i < this->length) 
        arr3->A[k++] = this->A[i++];
    while (j < arr2.length) 
        arr3->A[k++] = arr2.A[j++];

    arr3->length = k;
    Array result = *arr3;
    delete arr3;
    return result;
}

Array Array::intersection(const Array &arr2) {

    Array *arr3 = new Array(this->length < arr2.length ? this->length : arr2.length);
    int i = 0, j = 0, k = 0;

    while (i < this->length && j < arr2.length) {
        if (this->A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < this->A[i])
            j++;
        else { 
            arr3->A[k++] = this->A[i++];
            j++;
        }
    }
    arr3->length = k;
    Array result = *arr3;
    delete arr3;
    return result;
}


int main() {
    Array arr(10); // Using the constructor with size

    int choice, x, index;

    while (1) {
        cout << "\n--- MENU ---\n";
        cout << "1. Display\n2. Append\n3. Insert\n4. Delete\n5. Linear Search\n";
        cout << "6. Binary Search (Iterative)\n7. Max\n8. Min\n9. Sum\n10. Average\n";
        cout << "11. Reverse (Auxiliary Array)\n12. Reverse (Interchanging Elements)\n";
        cout << "13. Insert Sorted\n14. Check if Sorted\n15. Rearrange (Negative to Left)\n";
        cout << "16. Union of two arrays\n17. Intersection of two arrays\n18. Difference of two arrays\n";
        cout << "19. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr.Display();
                break;
            case 2:
                cout << "Enter element to append: ";
                cin >> x;
                arr.Append(x);
                break;
            case 3:
                cout << "Enter index and value: ";
                cin >> index >> x;
                arr.Insert(index, x);
                break;
            case 4:
                cout << "Enter index to delete: ";
                cin >> index;
                cout << "Deleted: " << arr.Delete(index) << "\n";
                break;
            case 5:
                cout << "Enter key to search: ";
                cin >> x;
                index = arr.linear_search(x);
                cout << (index != -1 ? "Found at " : "Not found ") << index << "\n";
                break;
            case 6:
                cout << "Enter key for binary search: ";
                cin >> x;
                index = arr.BS_iterative(x);
                cout << (index != -1 ? "Found at " : "Not found ") << index << "\n";
                break;
            case 7:
                cout << "Max: " << arr.get_max() << "\n";
                break;
            case 8:
                cout << "Min: " << arr.get_min() << "\n";
                break;
            case 9:
                cout << "Sum: " << arr.sum() << "\n";
                break;
            case 10:
                cout << "Average: " << arr.average() << "\n";
                break;
            case 11:
                arr.m1_auxiliary_array();
                cout << "Array reversed using auxiliary array.\n";
                break;
            case 12:
                arr.m2_interchanging_elements();
                cout << "Array reversed by interchanging elements.\n";
                break;
            case 13:
                cout << "Enter element to insert (maintaining sorted order): ";
                cin >> x;
                arr.insert_sorted(x);
                break;
            case 14:
                if (arr.is_sorted()) {
                    cout << "Array is sorted.\n";
                } else {
                    cout << "Array is not sorted.\n";
                }
                break;
            case 15:
                arr.rearrange();
                cout << "Array rearranged (negatives to left).\n";
                break;
            case 16: {
             
                Array arr1(5);
                arr1.Append(3); arr1.Append(5); arr1.Append(10); arr1.Append(15); arr1.Append(20);
                cout << "Array 1: "; arr1.Display();

                Array arr2(5);
                arr2.Append(1); arr2.Append(5); arr2.Append(12); arr2.Append(15); arr2.Append(25);
                cout << "Array 2: "; arr2.Display();

                Array arr_union = arr1.set_union(arr2);
                cout << "Union: ";
                arr_union.Display();
                break;
            }
            case 17: {
             
                Array arr1(5);
                arr1.Append(3); arr1.Append(5); arr1.Append(10); arr1.Append(15); arr1.Append(20);
                cout << "Array 1: "; arr1.Display();

                Array arr2(5);
                arr2.Append(1); arr2.Append(5); arr2.Append(12); arr2.Append(15); arr2.Append(25);
                cout << "Array 2: "; arr2.Display();

                Array arr_intersection = arr1.intersection(arr2);
                cout << "Intersection: ";
                arr_intersection.Display();
                break;
            }
            case 18: {
                
                Array arr1(5);
                arr1.Append(3); arr1.Append(5); arr1.Append(10); arr1.Append(15); arr1.Append(20);
                cout << "Array 1: "; arr1.Display();

                Array arr2(5);
                arr2.Append(1); arr2.Append(5); arr2.Append(12); arr2.Append(15); arr2.Append(25);
                cout << "Array 2: "; arr2.Display();

                Array arr_difference = arr1.difference(arr2);
                cout << "Difference (Array1 - Array2): ";
                arr_difference.Display();
                break;
            }
            case 19: 
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}