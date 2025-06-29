#include <iostream>
#include <vector>
using namespace std;

vector <int> set_intersection (vector <int> arr1 , vector <int> arr2){
    vector <int> result;
    
    for (int i = 0 ; i < arr1.size();  i++)  //doesn't check for duplicates
    {
        for (int j = 0 ; j < arr2.size() ; j++)
        {
            if (arr1[i] == arr2[j]) result.push_back(arr1[i]);
        }
    }
    return result;
}
int main(){
    vector <int> arr1 = {32,34,51,45,2};
    vector <int> arr2 = {20,34,10,2,30};
    
    vector <int > arr3 = set_intersection (arr1, arr2);
    
    for (auto val : arr3) cout << val << " " ;
}