#include <iostream>
using namespace std;

//SME - Single Missing Element
int SME_sorted(int arr[], int length){
    //Sum of n natural number -> n(n + 1)/ 2
    int sum_expected = (arr[length - 1] * ((arr[length - 1]) + 1) ) /2;
    
    int sum = 0;
    for (int i = 0 ; i < length ; i++) sum += arr[i];
    
    return sum_expected - sum;
}

//*****************************************************
//If index doesn't start from 1 
int SME_sorted2 (int arr[], int length){
    //General Formula for the Sum of an Arithmetic Progression 
    //S = n/2 (a + l) , a = first term, l = last term
    
    int a = arr[0] , l = arr[length -1];
    
    int sum_expected = ((l - a +1) * (a + l)) /2;
    
    int sum =0;
    for (int i = 0 ; i < length ; i++){
        sum += arr[i];
    }
    return sum_expected - sum ;
}

//Second method 
int SME_sorted3 (int arr[], int length){
    int diff = arr[0];
    
    for (int  i = 0 ; i < length ; i++){
        if (arr[i]  - i != diff){
            return i  + diff;
        }
    }
    return 0;
}

//*****************************************************

int main(){
    int arr[9] = {1,2,3,4,5,6,7,8,10};
    
    cout << "Missing Element: " << SME_sorted (arr,  9 ) << "\n";
    
    int arr2[9] = {4,5,6,7,8,9,10,12,13};
    
    cout << "Missing Element: " << SME_sorted2 (arr2, 9) << "\n";
    
    cout << "Missing Element: " << SME_sorted3 (arr2, 9);
    
    
    
}