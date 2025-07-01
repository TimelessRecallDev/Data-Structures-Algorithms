#include <stdio.h>

int get_length (char name[]){
    int length = 0; 

    while (name[length] != '\0'){
        length++;
    }
    return length;
}

int main(){
    char name[] = "Timeless";
    
    int length = get_length(name);
    
    printf("Length of the string : %d", length);
}