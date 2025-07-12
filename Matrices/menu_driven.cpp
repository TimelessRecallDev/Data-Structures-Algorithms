#include <iostream>
using namespace std;

class Diagonal {
private:
    int n;
    int* arr;

public:
    Diagonal(int n) {
        this->n = n;
        arr = new int[n]();  // 0 initialized
    }

    void set(int i, int j, int val) {
        if (i < 1 || i > n || j < 1 || j > n) return; //invalid position
        if (i == j) arr[i - 1] = val;
    }

    int get(int i, int j) {
        if (i < 1 || i > n || j < 1 || j > n) return -1;
        return (i == j) ? arr[i - 1] : 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~Diagonal() {
        delete[] arr;
    }
};

class LowerTri {
private: 
    int n;
    int* arr;

    int index(int i, int j) {
        return (i * (i - 1)) / 2 + (j - 1); //row major formula
    }

public:
    LowerTri(int n) {
        this-> n = n;
        arr = new int[(n *(n + 1)) / 2]();
    }
    void set(int i, int j, int value) {
        if (i< 1 || i >n || j< 1 || j >n) return;
        if (i >= j) arr[index(i, j)] = value;
    }
    int get(int i, int j) {
        if (i< 1 || i > n || j< 1 || j >n) return -1;
        return (i >= j) ? arr[index(i, j)] : 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~LowerTri() {
        delete[] arr;
    }
};

class UpperTri {
private: 
    int n;
    int* arr;

    int index(int i, int j) {
        return (j * (j - 1)) / 2 + (i - 1); //column major formula
    }
public:
    UpperTri(int n) {
        this-> n = n;
        arr = new int[(n *(n + 1)) / 2]();
    }  
    void set(int i, int j, int value) {
        if (i< 1 || i >n || j< 1 || j >n) return;
        if (i <= j) arr[index(i, j)] = value;
    }
    int get(int i, int j) {
        if (i< 1 || i > n || j< 1 || j >n) return -1;
        return (i <= j) ? arr[index(i, j)] : 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~UpperTri() {
        delete[] arr;
    }
};

class Symmetric {
private: 
    int n;
    int* arr;

    int index(int i, int j) {
        if (i < j) swap (i, j);
        return (i * (i - 1)) / 2 + (j - 1);  // lower triangular 
    }
public:
    Symmetric (int n) {
        this-> n = n;
        arr = new int[(n *(n + 1)) / 2]();
    }  
    void set(int i, int j, int value) {
        if (i< 1 || i >n || j< 1 || j >n) return;
        arr[index(i, j)] = value;
    }
    int get(int i, int j) {
        if (i< 1 || i > n || j< 1 || j >n) return -1;
        return arr[index(i, j)] ;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~Symmetric(){
        delete [] arr;
    }
};

class TriDiagonal {
private: 
    int n;
    int* arr;

    int index(int i, int j) {
        if (i == j) return (n - 1) + i - 1;  //main diagonal
        if (i == j + 1) return i - 2;  //lower diagonal
        if (i == j - 1) return (2* n - 1) + i - 1; //upper diagonal
        return -1;
    }
public:
    TriDiagonal (int n) {
        this-> n = n;
        arr = new int[3 * n - 2]();
    }
    void set(int i, int j, int value) {
        if (i< 1 || i >n || j< 1 || j >n) return;
        if (i == j || i == j + 1 || i == j - 1) arr[index(i, j)] = value;
    }
    int get(int i, int j) {
        if (i< 1 || i > n || j< 1 || j >n) return -1;
        return (i == j || i == j + 1 || i == j - 1) ? arr[index(i, j)] : 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~TriDiagonal(){
        delete [] arr;
    }    
};

class Toeplitz {
private: 
    int n;
    int* arr;

    int index(int i, int j) {
        if (i <= j) return j - i;
        if (i > j) return n + i - j - 1;
        return -1;
    }
 public:
    Toeplitz (int n) {
        this-> n = n;
        arr = new int[2 * n  - 1];
    }
    void set(int i, int j, int value) {
        if (i< 1 || i >n || j< 1 || j >n) return;
        arr[index(i, j)] = value;
    }
    int get(int i, int j) {
        if (i< 1 || i > n || j< 1 || j >n) return -1;
        return arr[index(i, j)] ;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~Toeplitz(){
        delete []arr;
    }
};


void fillMatrix(auto & matrix, int n) {
    cout << "Enter matrix elements row-wise:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int val;
            cin >> val;
            matrix.set(i, j, val);
        }
    }
    cout << "\nMatrix stored in compressed form:\n";
    matrix.display();
}

int main() {
    int choice, n;
    while (true) {
        cout << "\n===== Matrix Types =====\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Lower Triangular Matrix\n";
        cout << "3. Upper Triangular Matrix\n";
        cout << "4. Symmetric Matrix\n";
        cout << "5. Tridiagonal Matrix\n";
        cout << "6. Toeplitz Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Enter the matrix dimension: ";
        cin >> n;

        switch (choice) {
            case 1: {
                Diagonal m(n);
                fillMatrix(m, n);
                break;
            }
            case 2: {
                LowerTri m(n);
                fillMatrix(m, n);
                break;
            }
            case 3: {
                UpperTri m(n);
                fillMatrix(m, n);
                break;
            }
            case 4: {
                Symmetric m(n);
                fillMatrix(m, n);
                break;
            }
            case 5: {
                TriDiagonal m(n);
                fillMatrix(m, n);
                break;
            }
            case 6: {
                Toeplitz m(n);
                fillMatrix(m, n);
                break;
            }
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}