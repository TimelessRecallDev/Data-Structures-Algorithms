#include <iostream>
using namespace std;

void get_min_max (int arr[], int length){
    int max = arr[0];
    int min = arr[0];
    
    for (int i = 0 ; i < length ; i++){
        if (arr[i] > max){
            max = arr[i];
        } 
        else if (arr[i] < min){
            min = arr[i];
        }
    }
    
    cout << "Max Element : " << max << endl;
    cout << "Min Element : " << min << endl;
}
int main (){
    int arr[10] = {20,304,5,60,20,401,20,3, 5,1};
    
    get_min_max (arr, 10);
}