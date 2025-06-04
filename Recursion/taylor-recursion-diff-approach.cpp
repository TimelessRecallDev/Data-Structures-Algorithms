#include <iostream>

using namespace std;

// Recursive function to calculate power: x^n
double power(int x, int n) {
    if (n == 0) return 1;
    return x*power(x, n - 1);
}

// Recursive function to calculate factorial: n!
int fact(int n) {
    if (n == 0) return 1;
    return n*fact(n - 1);
}

// Recursive function to calculate the Taylor series sum
double calculate_taylor(int x, int n) {
    if (n == 0) return 1;
    return power(x, n) / (double)fact(n) +calculate_taylor(x, n - 1);
}

int main() {
    int x, n;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter number of terms: ";
    cin >> n;
    double result = calculate_taylor(x, n);
    cout << "Result: " << result << endl;
}