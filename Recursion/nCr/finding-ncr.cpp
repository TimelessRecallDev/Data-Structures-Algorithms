#include <iostream>
using namespace std;

int fact(int n);

int get_ncr (int n , int r)
{
    return fact (n) / (fact (n - r) * fact (r));
}
int fact(int n)
{
    if ( n == 0 ) return 1;
    else return n * fact (n - 1);
}
int main()
{
    int n , r;
    
    cin >> n >> r;
    
    cout << "Result: " << get_ncr (n ,r);
    
}