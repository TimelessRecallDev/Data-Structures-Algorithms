#include <stdio.h>
#include <stdlib.h>

char* reverse_string (char str[]){ //simple method - using another string
    int length = 0;
    for (int i = 0 ; str[i] != '\0' ; i++) length++;
    char *rev = (char *)malloc (length* sizeof(char));
    
    int i , j;
    for (i = 0 ,j = length - 1 ; i < length ; i++, j--){
        rev[i] = str[j];
    }
    rev[i] = '\0';
    
    return rev;
}

void rev_string (char str[]){ // 2nd method - swapping the elements

    int length = 0 ;   //can use strlen function also
    for (int i = 0 ; str[i] != '\0'; i++) length++;
    
    int  i = 0, j = length -1;
    
    for ( ; i < j ; i++, j--){
        int temp = str[i];
        str[i] = str[j];
        str[j] =temp;
    }
}

int main(){
    char str[100];
    
    printf("Enter the string: ");
    scanf("%s", &str);
    
    char* rev = reverse_string(str);
    
    printf("%s", rev);
    
    rev_string (str);
    
    printf("\n%s", str);
    
    free(rev);
    return 0;
    
}