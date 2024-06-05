//
//  main.cpp
//  C. Symmetry Makes Perfect
//
//  Created by Majd Kawak on 02/06/22.
//
 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

 
int compute_Cost(vector<char> &s, int n, map<char, int> &c) {
    
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // Fill the table
    for (int gap = 1; gap < n; gap++){
        for (int i = 0, j = gap; j < n; i++, j++){
            dp[i][j] = (s[i] == s[j])? dp[i+1][j-1] : (min(dp[i][j -1]+c[s[j]],dp[i+1][j]+c[s[i]]));
        }
    }
    /*
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout << dp[i][j] << " | ";
        }
        cout << endl;
        for (int j = 0; j<n; j++){
            cout << "----";
        }
        cout << endl;
    }
    */
    return dp[0][n - 1];
}
 
int main(int argc, const char * argv[]) {
    
    // Input Candies array size
    int string_Size;
    cin >> string_Size;
    
    // Input k flavors array size
    int k_size;
    cin >> k_size;
    
    // K pair flavors letter and their values
    map<char, int> letters_Cost;
    
    // Candies array string
    vector<char> candies_String(string_Size,0);
    
    // Input letters flavors and their values as paor
    char first = 'a';
    int input;
    
    for (int i = 0; i < k_size; i++){
        cin >> input;
        letters_Cost.insert(pair<char,int>(first,input));
        first++;
    }
    
    // Input string of candies
    for (int i = 0; i < string_Size; i++){
        cin >> candies_String[i];
    }
    
    // Display value
    cout << compute_Cost(candies_String, string_Size, letters_Cost);
    
    return 0;
}
