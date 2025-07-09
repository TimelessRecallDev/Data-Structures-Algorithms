#include <stdio.h>

void perm(char str[], int k){
    static int A[10] = {0};
    static char result[10];
    
    int i;
    if (str[k] == '\0'){
        result[k] = '\0';
        printf ("%s\n", result);
    }
    else{
        for ( i = 0 ; str[i] != '\0' ; i++){
            if (A[i] == 0){
                result[k] = str[i];
                A[i] = 1;
                perm (str, k+1);
                A[i] = 0;
            }
        }
    }
} 
int main(){
    char str[] = "ABC";
    
    perm(str, 0);
}