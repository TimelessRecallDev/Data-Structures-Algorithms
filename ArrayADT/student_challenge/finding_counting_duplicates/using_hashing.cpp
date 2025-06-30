#include <iostream>
using namespace std;

void find_count_duplicates (int arr[], int length, int max){
    int H[max + 1] = {0};
    
    for (int i =0 ; i < length ;i++){
        H[arr[i]]++;
    }
    
    for (int i = 0 ; i <= max ; i++){
        if (H[i] > 1)
          cout << i << " appeared " << H[i] << " times" << endl;
    }
}
int main(){
    int arr[10] = {6,6,8, 8, 9, 10 ,11 ,11 ,11,12};
    
    find_count_duplicates(arr, 10 , 12);
    
}