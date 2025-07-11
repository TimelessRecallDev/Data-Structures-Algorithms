#include <iostream>
#include <utility>
using namespace std;

class Matrix {
private:
    int n;
    int* arr;
    int index(int i, int j) {
     if (i < j) swap(i , j);
     return i *(i - 1) / 2 + (j - 1);
     
    }
public:
    Matrix(int n) {
        this->n = n;
        arr = new int[(n * (n + 1)) / 2];
    }

    void set(int i, int j, int value) {
            arr[index(i, j)] = value;
    }

    int get(int i, int j) {
            return arr[index(i, j)];
    }

    void display() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
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
    int n, value;

    cout << "Enter the dimension: ";
    cin >> n;

    Matrix m(n);

    cout << "Enter matrix elements:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> value;
            m.set(i, j, value); 
        }
    }

    cout << "Symmetric Matrix:\n";
    m.display();

    return 0;
}
