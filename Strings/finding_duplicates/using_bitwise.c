#include <stdio.h>

void find_dup (char str[]){
    int H = 0, x = 0; 
    
    for (int i = 0 ; str[i] != '\0'; i++){
        x = 1;
        x = x << (str[i] - 97);
        
        if ((H & x) >  0) {  //Masking
            printf ("Duplicate found :  %c\n", str[i]);
        }
        else {   //Merging 
            H = H | x ;
        }
    }
}
int main(){
    
    char str[] = "finding";
    
    find_dup (str);
    
}