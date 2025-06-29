#include <iostream>
#include <vector>
using namespace std;

vector <int> set_union (vector <int> arr1 , vector <int> arr2){
    vector <int> result;
    
    for (int i = 0 ; i < arr1.size() ; i++){
        result.push_back(arr1[i]);
    }
    for (int i = 0 ; i < arr2.size() ; i++){
         bool flag = true;
        for (int j = 0 ; j < arr1.size() ; j++){
            if (arr2[i] == arr1[j]) flag = false;
        }
        if (flag) result.push_back (arr2[i]);
    }
    
    return result;
}
int main(){
    vector <int> arr1 = {32,34,51,45,2};
    vector <int> arr2 = {20,34,10,2,30};
    
    vector <int > arr3 = set_union (arr1, arr2);
    
    for (auto val : arr3) cout << val << " " ;
}