#include <iostream>
using namespace std;

void change_case (char str[]){
    for (int i = 0 ; str[i] != '\0'; i++){
        if (str[i] >= 65 && str[i] <= 90){
            str[i] += 32;    //change to lowercase
        }
        else if (str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;     //change to uppercase;
        }
    }
}
int main(){
    
    char str[10];
    
    cout  << "Enter the string : " ;
    cin >> str;
    
    change_case(str);
    
    cout << "String : " << str;
}