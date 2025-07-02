#include <iostream>
#include <string>
using namespace std;

bool validate_str(string str){
  
  for (int i = 0 ; i < str.length() ; i++){
      if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 57)){
          return false;
      }
  }  
  return true;
}
int main(){
    
    string str;
    
    cout << "Enter the password: ";  //If it contains special char, it is not valid!
    cin >> str ;
    
    if (validate_str(str)) {
        cout  << "Password is valid!";
    }
    else cout << "Password is not valid";
    
}