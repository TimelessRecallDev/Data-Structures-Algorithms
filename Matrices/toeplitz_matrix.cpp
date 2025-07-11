#include <iostream>
using namespace std;

class Matrix {
private:
    int n;
    int* arr;

    int index(int i, int j) {
   
        if (i <= j) return j - i;         //upper triangle
        else  return n + i - j - 1;   // lower triangle
    }

public:
    Matrix(int n) {
        this->n = n;
        arr = new int[2 * n - 1](); 
    }

    void set(int i, int j, int val) {
            arr[index(i, j)] = val;
    }

    int get(int i, int j) {
        return arr[index(i, j)];
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
