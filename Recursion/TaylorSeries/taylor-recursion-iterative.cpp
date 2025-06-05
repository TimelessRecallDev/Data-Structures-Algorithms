#include <iostream>
using namespace std;

double cal_taylor (int x, int n) //Iterative way of calculating taylor series
{
    double result = 1;
    for (int i = n ; i  > 0 ; i --)
    {
        result = 1 + (x * result) / i ;
    }
    return result;
}
int main()
{
    int x , n;
    
    cin >> x >> n;
    
    double result = cal_taylor(x , n);
    
    cout << "Result : " << result;
    
}