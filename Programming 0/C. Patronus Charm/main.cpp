//
//  main.cpp
//  C. Patronus Charm
//
//  Created by Majd Kawak on 1/11/23.
//

#include <iostream>
#include <vector>

using namespace std;

int compute_LIS(vector<int> &arr, int arr_Size) {

    // Max sum of LIS elements
    int max = 0;
    
    // Initialize all value vector to original array
    vector <int> max_Sum_At_Index = arr;

    // Compute LIS with SUM at index
    for (int i = 1; i < arr_Size; i++) {
        for(int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && max_Sum_At_Index[i] < max_Sum_At_Index[j] + arr[i]) {
                max_Sum_At_Index[i] = arr[i] + max_Sum_At_Index[j];
                max = (max < max_Sum_At_Index[i])? max_Sum_At_Index[i] : max;
            }
        }
    }

    return max;
}

int main(int argc, const char * argv[]) {
    
    // Input Array
    int arr_Size;
    cin >> arr_Size;
 
    vector<int> arr(arr_Size);
    for (int i = 0; i < arr_Size; i++){
        cin >> arr[i];
    }
    
    // Compute LIS with SUM
    cout << compute_LIS(arr, arr_Size) << endl;
    
    return 0;
}
