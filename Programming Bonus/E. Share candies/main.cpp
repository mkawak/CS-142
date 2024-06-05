//
//  main.cpp
//  E. Share candies
//
//  Created by Majd on 3/9/23.
//

#include <iostream>
#include <vector>

using namespace std;
int compute_diff(vector<int> &vec) {
    int result = 0;
    
    for(int it = 0; it < vec.size()-1; it++) {
        if(vec[it] - vec[it+1]>0){
            result += vec[it] - vec[it+1];
        }
    }
    
    return result;
}
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    int total_candies = 0;
    vector<int> total_distance;
    
    int input;
    for(int it = 0; it < n; it++){
        cin >> input;
        total_distance.push_back(input);
        cin >> input;
        total_candies+=input;
    }
    
    sort(total_distance.begin(), total_distance.end(), [](int a, int b) {
        return a > b;
    });
    for(int it = 0; it < total_distance.size(); it++){
        cout << total_distance[it] << endl;
    }
    int total_diff = compute_diff(total_distance);
    
    cout << (total_candies - total_diff) / n << endl;
    return 0;
}
