#include<iostream>
#include<math.h>
using namespace std;

struct Term{
    int coeff;
    int power;
};

class Polynomial{
private:
    int n;   // for storing no of terms
    struct Term *t;  
public:
     Polynomial(int n){
        this-> n = n;
        t = new Term [n]; 
     }

     ~Polynomial(){
        delete[] t;
     }

     void input();
     double evaluate(int x);
};

void Polynomial :: input (){
    cout << "\nEnter the elemenets:\n";

    for (int i = 0 ; i < n ; i++){
        cin >> t[i].coeff >> t[i].power;
    }
}

double Polynomial :: evaluate(int x){

    double sum = 0;

    for (int i = 0 ; i < n ; i++){
        sum += t[i].coeff * pow(x, t[i].power);
    }
    return sum;
}

int main(){

    int terms;

    cout << "Enter the number of terms: ";
    cin >> terms;

    Polynomial p (terms);

    p.input();

    int x;
    cout << "\nEnter the value of x: ";
    cin >> x;

    cout << "Result: " << p.evaluate(x);
}