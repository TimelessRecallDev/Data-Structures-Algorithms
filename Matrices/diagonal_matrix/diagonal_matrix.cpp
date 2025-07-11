#include <iostream>
using namespace std;

class Matrix{
private: 
         int n;
         int *arr;
public: 
         Matrix(int n){
            this-> n = n;
            arr= new int [n];
         }
         void set (int i, int j, int value);
         int get (int i , int j);
         void display();
         ~Matrix(){
            delete []arr;
         }
};

void Matrix:: set(int i, int j, int value){
    if (i == j){
        arr[i -1] = value;
    }
}

int Matrix :: get(int i , int j){
    if (i == j) {
        return arr[i -1];
    }
    else return 0;
}

void Matrix:: display(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (i == j) cout << arr[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
int main(){
    Matrix m(5);

    m.set(1,1,5);
    m.set(2,2,10);
    m.set(3,3,15);
    m.set(4,4,20);
    m.set(5,5,25);
    
    cout << m.get (2,2) << endl;

    m.display();



}