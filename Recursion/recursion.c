#include <iostream>
using namespace std;

void fun_tail (int n);
void fun_head (int n);

int main(){
    int x ;
    cout << "Enter a number: ";
    cin >>  x;
    
    fun_tail (x);
    fun_head (x);
}

void fun_tail (int n) //Example of tail recursion
{
    if (n > 0)
    {
        cout << n << endl;
        fun_tail (n - 1); 
        
    }
}

void fun_head (int n)  //Example of head recursion
{
    if (n  > 0)
    {
        fun_head (n - 1);
        cout << n << endl;
    }
}