#include <stdio.h>

void finding_duplicates (char str[]){
    int H[26] = {0};   //for lowercase letters ranging 97-122
    
    for (int i = 0 ; str[i] != '\0' ; i++){
        H[str[i] - 97]++;
    }
    for (int  i = 0 ; i < 26 ; i++){
        if (H[i] > 1) {
            printf ("%c is repeated %i times\n", (i + 97) ,  H[i]);
        }
    }
}
int main (){
    
    char str [] = "finding";
    
    finding_duplicates (str);
}