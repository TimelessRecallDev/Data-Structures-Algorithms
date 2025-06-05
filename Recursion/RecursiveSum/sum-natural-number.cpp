#include <iostream>
using namespace std;

int cal_sum(int n) {
    if (n == 0)
        return 0;
    else
        return n + cal_sum(n - 1);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = cal_sum(n);
    cout << "Sum of " << n << " natural numbers: " << result
