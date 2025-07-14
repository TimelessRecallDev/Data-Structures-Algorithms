#include<iostream>
using namespace std;

struct Term{
    int coeff;
    int power;
};

class Polynomial{
private:
    int n;   //no of terms
    struct Term *t;    //pointer to the structure 
public:
     Polynomial(int n){
        this-> n = n;
        t = new Term [n]; 
     }

     ~Polynomial(){
        delete[] t;
     }

     void input();
};

void Polynomial :: input (){
    cout << "Enter the elemenets: ";

    for (int i = 0 ; i < n ; i++){
        cin >> t[i].coeff >> t[i].power;
    }
}

int main(){
    Polynomial p (5);

    p.input();
}