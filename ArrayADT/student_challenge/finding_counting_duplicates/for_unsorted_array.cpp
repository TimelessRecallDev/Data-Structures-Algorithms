#include <iostream>
using namespace std;

void find_count_duplicates (int arr[], int n){
    
    int count;
    for (int i = 0 ; i < n  -1 ; i ++)
    {
            count = 1;
            if (arr[i] != -1)
              for (int j = i+ 1;  j < n ; j++){
                if (arr[i] == arr[j]){
                    count++;
                    arr[j] = -1;
                }
        }
        if (count > 1)cout << arr[i] << " appeared " << count << " times." << endl;
    }
}
int main(){
    int arr[10] = {20,59,59,59,2,1,1,4,5,6};
    
    find_count_duplicates(arr, 10);
    
}