#include<stdio.h>

void compare_strings(char str[], char str2[]){
    int i, j;
    for (i =0 , j= 0; str[i] != '\0' && str2[j] != '\0'; i++, j++){
        if (str[i] != str2[j]){
            break;
        }
    }
    if (str[i] == str2[j]) printf("Both strings are equal\n");
    else if (str[i] < str2[j]) printf("first string is smaller\n");
    else printf("second string is smaller\n");
}
int main(){
    char str[100];
    char str2[100];
    
    printf("Enter two strings to compare: \n");
    scanf("%s %s", &str, &str2);
    
    compare_strings(str, str2);
}