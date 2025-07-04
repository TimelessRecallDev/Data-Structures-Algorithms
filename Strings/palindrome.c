#include <stdio.h>
#include <string.h>

void rev_string(char str[], int length) {
    int i = 0, j = length - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void compare_strings(char str1[], char str2[]) {
    if (strcmp(str1, str2) == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}

void palindrome(char str[]) {
    int length = strlen(str);
    char rev[100]; 
    strcpy(rev, str);
    rev_string(rev, length);
    compare_strings(str, rev);
}

//another method 
void palindrome2(char str[]) {
    int length = strlen(str);
    int i = 0 ,  j = length - 1;
    
    for ( ; i < j ; i++,  j--){
        if (str[i] != str[j]){
        printf("Not palindrome!");
        return;
        }
    }
    printf("Palindrome");
}
int main() {
    char str[100];
    printf("Enter string: \n");
    scanf("%s", str);
    palindrome(str);
    palindrome2(str);
    return 0;
}
