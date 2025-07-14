#include<iostream>
#include<math.h>
using namespace std;

struct Term{
    int coeff;
    int power;
};

class Polynomial{
private:
    int n;   
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

     friend Polynomial sum (Polynomial p1, Polynomial p2);
};

void Polynomial :: input (){
    cout << "\nEnter the elemenets:\n";

    for (int i = 0 ; i < n ; i++){
        cin >> t[i].coeff >> t[i].power;
    }
}

Polynomial sum (Polynomial p1, Polynomial p2){   //addition of two polynomials
    Polynomial sum (p1.n + p2.n);

    int i = 0, j = 0, k = 0;

    while (i < p1.n && j < p2.n){
        if (p1.t[i].power > p2.t[j].power) sum.t[k++] = p1.t[i++];
        else if (p1.t[i].power < p2.t[j].power) sum.t[k++] = p2.t[j++];
        else{
            sum.t[k].power = p1.t[i].power;
            sum.t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    for ( ; i < p1.n ; i++) sum.t[k++] = p1.t[i];
    for ( ; j < p2.n ; j++) sum.t[k++] = p2.t[j];

    return sum;
}


int main(){

    int term1;

    cout << "Enter the number of terms of first polynomial: ";
    cin >> term1;

    Polynomial p1 (term1);

    p1.input();

    int term2;

    cout << "Enter the number of terms of second polynomial: ";
    cin >> term2;

    Polynomial p2 (term2);

}