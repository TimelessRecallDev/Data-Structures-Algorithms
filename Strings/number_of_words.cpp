#include <iostream>
using namespace std;

void num_of_words(char str[]){  //dealing with white spaces
    int words = 0;
    for (int i = 0 ; str[i] != '\0'; i++){
        if (str[i] == ' ' && str[i - 1] != ' '){
            words++;
        }
    }
    cout << "Number of words: " << words + 1;
}
int main(){
    char str[20] = "Timeless   Recall";
    
    num_of_words(str);
    
    
}