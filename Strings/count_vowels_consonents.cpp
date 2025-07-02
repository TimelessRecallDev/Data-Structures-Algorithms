#include <iostream>
using namespace std;

void count_v_c (char str[]){
    
    int vcount = 0 , ccount =0;
    
    for (int i = 0 ; str[i] != '\0' ; i++){
        
        if (str[i] == 'a' ||str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||str[i] == 'A'  ||str[i] == 'E'  ||str[i] == 'I'  ||str[i] == 'O'  ||str[i] == 'U'){
            vcount++;
        }
        else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 &&  str[i] <= 122)){
            ccount++;
        }
    }
    
    cout << "Number of vowels: " << vcount << endl;
    cout << "Number of constants: " << ccount << endl;
}
int main(){
    char str[10];
    
    cout << "Enter the string: ";
    cin >> str;
    
    
    count_v_c(str);
}