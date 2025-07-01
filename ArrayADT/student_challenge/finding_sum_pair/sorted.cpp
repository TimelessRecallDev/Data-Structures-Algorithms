#include <iostream>
using namespace std;

//finding sum of pair k for array
void finding_sum_pair(int arr[], int length , int k){ 
    int i = 0 , j = length -1;
    
    while (i < j){
        if (arr[i] + arr[j] == k){
            cout << arr[i] << " + " << arr[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < k) i++;
        else j--;
    }
}

//Note- Array must be sorted
int main(){
    int arr[10] = {1,3,4,5,6,8,9,10,12,14};
    
    finding_sum_pair (arr , 10, 10);
}
