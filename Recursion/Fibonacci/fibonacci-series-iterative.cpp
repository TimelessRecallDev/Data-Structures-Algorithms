#include <iostream>
using namespace std;

int fib (int n);

int main()
{
    int n;
    
    cout << "Enter the number of terms :";
    cin >> n; 
    
    cout << "Result : " << fib (n);
}

int fib (int n)  //tc : O(n) & SC : O(1)
{
    if (n <= 1) return n;
    
    int first_term = 0 ;
    int second_term = 1;
    int result ;
    
    for (int i = 2 ; i <= n ; i++)
    {
        result = first_term + second_term;
        first_term =second_term;
        second_term = result;
    }
    
    return result;
}