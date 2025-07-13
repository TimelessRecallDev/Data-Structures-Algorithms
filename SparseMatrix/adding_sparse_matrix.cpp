#include <iostream>
using namespace std;

struct Element {
    int x;
    int y;
    int val;
};

class Sparse {
private:
    int m, n, num;
public:
    Element* p;

    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        p = new Element[num];
    }

    void input() {
        for (int i = 0; i < num; i++) {
            cin >> p[i].x >> p[i].y >> p[i].val;
        }
    }

    void display() const {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (k < num && p[k].x == i && p[k].y == j)
                    cout << p[k++].val << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    ~Sparse() {
        delete[] p;
    }

    friend Sparse sum(const Sparse& s1, const Sparse& s2);
};

Sparse sum(const Sparse& s1, const Sparse& s2) {
    if (s1.m != s2.m || s1.n != s2.n) {
        return Sparse(0, 0, 0);
    }

    int i = 0, j = 0, k = 0;
    Sparse result(s1.m, s1.n, s1.num + s2.num);

    while (i < s1.num && j < s2.num) {
        if (s1.p[i].x < s2.p[j].x)
            result.p[k++] = s1.p[i++];
        else if (s1.p[i].x > s2.p[j].x)
            result.p[k++] = s2.p[j++];
        else {
            if (s1.p[i].y < s2.p[j].y)
                result.p[k++] = s1.p[i++];
            else if (s1.p[i].y > s2.p[j].y)
                result.p[k++] = s2.p[j++];
            else {
                result.p[k] = s1.p[i];
                result.p[k++].val += s2.p[j++].val;
                i++;
            }
        }
    }

    while (i < s1.num)
        result.p[k++] = s1.p[i++];
    while (j < s2.num)
        result.p[k++] = s2.p[j++];

    result.num = k;
    return result;
}

int main() {
    int m1, n1, num1;
    cout << "Enter matrix dimensions: ";
    cin >> m1 >> n1;
    cout << "Enter number of non-zero elements: ";
    cin >> num1;

    Sparse s1(m1, n1, num1);
    cout << "Enter elements of first matrix:\n";
    s1.input();

    int m2, n2, num2;
    cout << "Enter matrix dimensions: ";
    cin >> m2 >> n2;
    cout << "Enter number of non-zero elements: ";
    cin >> num2;

    Sparse s2(m2, n2, num2);
    cout << "Enter elements of second matrix:\n";
    s2.input();

    Sparse s3 = sum(s1, s2);
    cout << "\nSum Matrix:\n";
    s3.display();

    return 0;
}
