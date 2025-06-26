#include <iostream>
using namespace std;

// A recursive function that prints the value of n
// and then calls itself twice with (n - 1)

void fun(int n) {
    if (n > 0) {
        cout << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}

int main() {
    fun(3);
    return 0;
}
