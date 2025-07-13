#include <iostream>
using namespace std;

struct Element {
    int i, j, x;
};

class Sparse {
private:
    int m, n, num;
    Element* p;

public:
    Sparse(int rows, int cols, int nonZero) {
        m = rows;
        n = cols;
        num = nonZero;
        p = new Element[num];
    }

    void input() {
        cout << "Enter non-zero elements:\n";
        for (int k = 0; k < num; ++k)
            cin >> p[k].i >> p[k].j >> p[k].x;
    }

    void display(){
        int k = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (k < num && p[k].i == i && p[k].j == j)
                    cout << p[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
        }
    }

    ~Sparse() {
        delete[] p;
    }
};

int main() {
    int m, n, num;
    cout << "Enter matrix dimensions: ";
    cin >> m >> n;

    cout << "Enter number of non-zero elements: ";
    cin >> num;

    Sparse s(m, n, num);
    s.input();
    cout << "Matrix:\n";
    s.display();
}
