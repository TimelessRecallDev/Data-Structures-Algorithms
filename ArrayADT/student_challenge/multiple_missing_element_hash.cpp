#include <iostream>
using namespace std;

//MME - Multiple Missing elements  (Using hash table)
void MME_hash (int arr[], int length,  int high , int low){
    int H [high] = {0};
    
    for (int i = 0 ; i < length ;i++){
        H[arr[i]]++;
    }
    for (int i = low ; i <= high ; i++){
        if(H[i] == 0) cout << i << " " ;
    }
}
int main(){
    int arr[10] = {6,7,8,18,5,3,2,1,9,10};
    
    cout << "Missing elements: " ;
    MME_hash (arr, 10, 18 , 1);
}