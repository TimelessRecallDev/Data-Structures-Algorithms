#include <iostream>
using namespace std;

int fib_memo (int n)   //Reduced the TC from O(2^N) to O(N)
{
    static int F[10] = {0};  
    
    if (n <= 1) {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 1] == 0) {
            F[n - 1] = fib_memo(n - 1);  
        }
        
        if (F[n - 2] == 0) {
            F [n - 2] = fib_memo (n -2);
        }
        F[n] = F[n -1] + F[n -2];
        return F [n -1] + F[ n -2];
    }
}
int main()
{
    int n; 
    
    cout << "Enter the number of terms: ";
    cin >> n;
    
    cout << "Result : " << fib_memo(n);
}
