#include <iostream>
using namespace std;

class Array{

private:
        int *A;
        int size;
        int length;
public:
       Array (int s){
           size = s;
           A =new int [size];
       }
       void set_length(int l)
       {
           length = l;
       }
       void set_array () {
           for (int i {0};  i < length ; i++)
           {
               cin >> A[i];
           }
       }
       void display () {
           for (int i {0} ; i < length ; i++)
           {
               cout << A[i] << " ";
           }
       } 
       void add (int x){                   //for adding
           if (length > size ) return;
           A[length++]  = x; 
       }
       void insert (int index , int x){     //for inserting
           if (index <0 || index > length) return;
           for (int i = length ; i > index ; i--)
           {
               A[i] = A[i - 1];
           }
           A[index ] = x;
           length++;
       }
        ~Array() {
            delete[] A;
            A = nullptr;
        }
                     
};

int main()
{
    int size , length; 
    
    cout << "Enter the size of array : ";
    cin >> size;
    
    Array arr(size);
    
    cout << "How many elements: ";
    cin >> length;
    
    arr.set_length(length);
    
    arr.set_array();
    

    cout << "The elements are : ";
    arr.display ();
}