#include <iostream>
using namespace std;

// Not efficient TC : O(n)
// long power_rec(int base, int exponent) {
//     if (exponent == 0)
//         return 1;
//     return base * power_rec(base, exponent - 1);
// }

// TC: O(log n)
long power_rec(int base , int exponent)
{
    if (exponent == 0) return 1;
    else if (exponent % 2 == 0) return power_rec (base *base , exponent /2);
    else return base *power_rec (base *base, (exponent - 1) /2);
}

int main() {
    int x, power;
    cout << "Enter number & power: ";
    cin >> x >> power;

    cout << "Result: " << power_rec(x, power);
}
