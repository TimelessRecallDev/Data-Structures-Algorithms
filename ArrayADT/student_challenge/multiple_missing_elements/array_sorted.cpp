#include <iostream>
using namespace std;

//MME - Multiple Missing Elements
void MME_sorted (int arr[], int length){
    int diff = arr[0];
    
    for (int i = 0 ; i < length ; i++){
        if (arr[i] - i != diff){
            while (diff < arr[i] - i){
                cout << i + diff << " ";
                diff++;
            }
        }
    }
}
int main(){
    int arr[10] = {6,7,8,10,13,14,15,16,17, 18};
    
    MME_sorted (arr, 10);
}