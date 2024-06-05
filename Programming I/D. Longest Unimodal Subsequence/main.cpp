//
//  main.cpp
//  D. Longest Unimodal Subsequence
//
//  Created by Majd Kawak on 02/06/22.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compute_LUS(int arr[], int arr_Size) {
    
    // Compute LIS from left to right
    // LIS max value
    int lis_Max = 0;
    
    // Holds index LIS values, initialize all elements to 1
    vector<int> lis_Index_Val(arr_Size, 1);
    
    // Compute LIS
    for (int i = 1; i < arr_Size; i++) {
        for(int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis_Index_Val[i] < lis_Index_Val[j] + 1) {
                lis_Index_Val[i] = lis_Index_Val[j] + 1;
                lis_Max = (lis_Max < lis_Index_Val[i])? lis_Index_Val[i] : lis_Max;
            }
        }
    }
    //------------------------------------------
    
    // Compute LDS from right to left
    // LDS max value
    int lds_Max = 0;
    
    // Holds index LDS values, initialize all elements to 1
    vector<int> lds_Index_Val(arr_Size, 1);
    
    // Compute LDS
    for (int i = arr_Size-2; i >=0; i--) {
        for(int j = arr_Size-1; j > i; j--) {
            if (arr[i] > arr[j] && lds_Index_Val[i] < lds_Index_Val[j] + 1) {
                lds_Index_Val[i] = lds_Index_Val[j] + 1;
                lds_Max = (lds_Max < lds_Index_Val[i])? lds_Index_Val[i] : lds_Max;
            }
        }
    }
    //------------------------------------------
    
    // Compute LUS
    // Using Bitonic Sequance Logic
    // Sum of values(LIS+LDS) at same index - 1 (we -1 to remove index double counted in LIS and LDS)
    // LUS max value
    int lus_Max = 0;
    
    // Initialize all value vector to 0
    vector<int> lus_Index_Val(arr_Size, 0);
    
    for (int i = 0; i < arr_Size; i++){
        lus_Index_Val[i] = (lis_Index_Val[i] + lds_Index_Val[i]) - 1;
        lus_Max = (lus_Max < lus_Index_Val[i]) ? lus_Index_Val[i] : lus_Max;
    }
    
    // Return LUS max value
    return lus_Max;
}

int main(int argc, const char * argv[]) {
    
    // Input Array Size
    int arr_Size;
    cin >> arr_Size;
    
    // Input Array
    int arr[arr_Size];
    for (int i = 0; i < arr_Size; i++){
        cin >> arr[i];
    }
    
    // Compute LUS
    cout << compute_LUS(arr, arr_Size) << endl;
    
    return 0;
}
