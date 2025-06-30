#include <iostream>
using namespace std;

void finding_duplicates(int arr[], int length)
{
    int last_duplicate = 0;
    for (int i = 0 ; i< length -1 ; i++){
        if (arr[i] == arr[i+1] && last_duplicate != arr[i]){
            cout << arr[i] << " " ;
            last_duplicate = arr[i];
            
        }
    }
}

void counting_duplicates (int arr[], int length){
    int j =0 ;
    
    for (int i = 0 ; i < length -1 ; i++){
        if (arr[i] == arr[i +1]){
            j = i;
            while (arr[i] == arr[j]) j++;
            cout << arr[i] << " appeared " << j - i << " times " << endl;
            i = j -1;
        }
    }
}

void unsorted_find_count_duplicates (int arr[], int n){
    
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

void hashing_find_count_duplicates (int arr[], int length, int max){
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
    
    cout << "Duplicate Elements: ";
    finding_duplicates (arr, 10);
    
    cout << "\n";
    
    counting_duplicates (arr, 10);
    
}