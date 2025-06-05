#include <iostream>
using namespace std;

double cal_taylor (int x, int n) //Taylor recursion using horner's rule
{
    static double result = 1;
    if (n == 0) return result;
    
    else {
        result = 1 + x * result / n;
        return cal_taylor (x , n- 1);
    }
}
int main()
{
    int x , n;
    
    cin >> x >> n;
    
    cout << "Result: " << cal_taylor (x , n);
    
}