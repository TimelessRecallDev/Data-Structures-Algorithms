#include <iostream>
using namespace std;

void find_sum_pair (int arr[], int n, int k){
    for (int i = 0 ; i < n -1 ; i++){
        for (int j = i +1 ; j < n ; j++){
            if (arr[i]  + arr[j] == k) {
                cout << arr[i] << "+" <<  arr[j] << " = " << k << endl ;
           }
        }
    }
}

void find_sum_pair_hashing (int arr[], int n , int k, int max){
    int H[max] = {0};
    
    for (int i = 0 ; i < n ; i++){
        
        if (H[k - arr[i]] != 0 ) cout << arr[i] << "+" << k -arr[i] << " = " << k;
        
        H[arr[i]]++;
    }
    
}
int main()
{
    int arr[10] = {100, 20, 30, 40, 50, 60, 70, 80, 90,10};
    
    find_sum_pair(arr, 10 , 30);
    find_sum_pair_hashing (arr, 10 , 30, 100);
    
    
}