//
//  main.cpp
//  A. Finding the Rank
//
//  Created by Majd on 3/5/23.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Priority Queue to keep numbers in a sorted manner
    priority_queue<int> p_q;
    // Map to save the rank of each number
    map<int, int> rank;
    
    
    // Input n
    int n;
    cin >> n;
    
    int input_Value;
    
    for(int it = 0; it < n; it++){
        cin >> input_Value;
        p_q.push(input_Value);
    }
    
    
    // Calculate rank starting from 1
    int rank_At_Index = 1;
    while (!p_q.empty()) {
        int it = p_q.top();
        p_q.pop();
        if(rank[it]==0){
            rank[it] = rank_At_Index;
            rank_At_Index++;
        }
        else{
            rank_At_Index++;
        }
    }
    
    // Output query
    vector<int> output_Vec;
    int m;
    cin >> m;
    
    int num_To_Output;
    for(int it = 0; it < m; it++){
        cin >> num_To_Output;
        output_Vec.push_back(rank[num_To_Output]);
    }
    for(int it = 0; it < output_Vec.size(); it++){
        cout << output_Vec[it] << endl;
    }
    return 0;
}
