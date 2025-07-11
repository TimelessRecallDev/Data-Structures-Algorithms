#include <iostream>
using namespace std;

class Matrix {
private:
    int n;
    int* arr;

    int index(int i, int j) {
   
        if (i == j) return n - 1 + i;         // Main diagonal
        else if (i == j + 1) return 2 * n - 1 + j; // Lower diagonal
        else if (j == i + 1) return i;        // Upper diagonal
        return -1; 
    }

public:
    Matrix(int n) {
        this->n = n;
        arr = new int[3 * n - 2](); 
    }

    void set(int i, int j, int val) {
        if (abs(i - j) <= 1) {
            arr[index(i, j)] = val;
        }
    }

    int get(int i, int j) {
        if (abs(i - j) <= 1) return arr[index(i, j)];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter the matrix dimension ";
    cin >> n;

    Matrix m(n);

    cout << "Enter elements row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            m.set(i, j, val);
        }
    }

    cout << "\nThe matrix is:\n";
    m.display();

    return 0;
}
