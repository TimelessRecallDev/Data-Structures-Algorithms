#include <stdio.h>

void anagram (char str1[], char str2[]){  //using hash-table
    int H[26] = {0};
    
    for (int  i  = 0 ; str1[i] != '\0' ; i++){
        H[str1[i] - 97]++;
    }
    for (int i = 0 ; str2[i] != '\0' ; i++){
        H[str2[i] - 97]--;
        
        if (H[str2[i] - 97] < 0){
           printf("Not Anagram ");
           return;
        } 
    }
    printf("Anagram");
    
}
int main(){
    char str1[] = "decimal";
    char str2[] = "medical";
    
    anagram(str1, str2);
}