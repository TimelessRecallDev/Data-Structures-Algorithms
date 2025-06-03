#include <iostream>
using namespace std;

// fun calls itself with fun(n-1) as argument inside the recursive call

int fun(int n) {
    if (n > 100)
        return n - 10;
    return fun(fun(n + 11));
}

int main() {
    cout << fun(95) << endl;  // Output: 91
    return 0;
}
