#include <iostream>
#include <cmath>
using namespace std;

struct Term {
    int coeff;
    int power;
};

class Polynomial {
private:
    int n;
    struct Term* t;
public:
    Polynomial(int n) {
        this->n = n;
        t = new Term[n];
    }

    ~Polynomial() {
        delete[] t;
    }

    void input();
    double evaluate(int x);
    void display();

    friend Polynomial sum(Polynomial p1, Polynomial p2);
};

void Polynomial::input() {
    cout << "Enter each term as: \n";
    for (int i = 0; i < n; i++) {
        cout << "Term " << i + 1 << ": ";
        cin >> t[i].coeff >> t[i].power;
    }
}

void Polynomial::display() {
    cout << "Polynomial: ";
    if (n == 0) {
        cout << "0" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (t[i].coeff == 0) continue;

        if (i > 0 && t[i].coeff > 0) {
            cout << "+";
        }
        cout << t[i].coeff;
        if (t[i].power > 0) {
            cout << "x";
            if (t[i].power > 1) {
                cout << "^" << t[i].power;
            }
        }
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

Polynomial sum(Polynomial p1, Polynomial p2) {
    Polynomial result(p1.n + p2.n); 
    int i = 0, j = 0, k = 0;

    while (i < p1.n && j < p2.n) {
        if (p1.t[i].power > p2.t[j].power)
            result.t[k++] = p1.t[i++];
        else if (p1.t[i].power < p2.t[j].power)
            result.t[k++] = p2.t[j++];
        else {
            result.t[k].power = p1.t[i].power;
            result.t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }

    while (i < p1.n)
        result.t[k++] = p1.t[i++];
    while (j < p2.n)
        result.t[k++] = p2.t[j++];

    result.n = k;
    return result;
}

double Polynomial::evaluate(int x) {
    double value = 0;
    for (int i = 0; i < n; i++) {
        value += t[i].coeff * pow(x, t[i].power);
    }
    return value;
}

int main() {
    int term1, term2;

    cout << "Enter the number of terms of first polynomial: ";
    cin >> term1;
    Polynomial p1(term1);
    p1.input();

    cout << "Enter the number of terms of second polynomial: ";
    cin >> term2;
    Polynomial p2(term2);
    p2.input();

    cout << "\nFirst ";
    p1.display();

    cout << "Second ";
    p2.display();

    Polynomial p3 = sum(p1, p2);

    cout << "Sum ";
    p3.display();

    int x;
    cout << "\nEnter value of x to evaluate sum polynomial: ";
    cin >> x;

    cout << "Value at x = " << x << " is: " << p3.evaluate(x) << endl;

    return 0;
}
