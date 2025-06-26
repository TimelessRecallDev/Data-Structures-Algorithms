#include <iostream>
using namespace std;

int ncr_rec (int n , int r)
{
    if (r == 0 || n ==r) return 1;
    else      //Using pascal triangle
    {
        return ncr_rec (n - 1 ,r -1) + ncr_rec (n -1 ,r);
    }
}
int main()
{
    int n , r;
    
    cin >> n >> r;
    
    cout << "Result: " << ncr_rec (n ,r);
}