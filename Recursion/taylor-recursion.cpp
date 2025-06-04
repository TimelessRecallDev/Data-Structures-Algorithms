#include <iostream>
using namespace std;

int cal_taylor (int x , int n)
{
    static int p {1} , f {1};
    int r;
    
    if (n == 0) return 1;
    else
    {
        r = cal_taylor (x , n -1);
        p = p * x;
        f = f * n;
        return r + p / f;
        
    }
}
int main()
{
    int x , n;
    
    cin >> x >> n;
    
    cout << "Result : " << cal_taylor (x , n);
    
}