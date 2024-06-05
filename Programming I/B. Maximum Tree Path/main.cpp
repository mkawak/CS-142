//
//  main.cpp
//  B. Maximum Tree Path
//
//  Created by Majd on 02/06/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_List(vector<vector<int>> &adj_list, vector<int> &parent_Node){
    for (int i = 0; i < adj_list.size(); i++)
    {
        cout << "Node [" << i << "] P[" << parent_Node[i] << "] ->";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------- " << endl;
}

int findMaxSumPath(vector<vector<int>> &adjList, int node, vector<int> &weight, int &maxSum) {
    
    // We have at least one node as a child
    if (!adjList[node].empty()){
        priority_queue<int> pq;
        for(int i = 0; i < adjList[node].size(); i++){
            int childWeightPath = findMaxSumPath(adjList, adjList[node][i], weight, maxSum);
            pq.push(childWeightPath);
        }
        bool modified = false;
        int singlePath;
        int andTreePath;
        int max_element1 = pq.top();
        pq.pop();
        
        // Store single path
        singlePath = (max_element1 + weight[node]>weight[node])?max_element1 + weight[node]:weight[node];
        
        // Compute ^ Tree Max Sum
        if(!pq.empty()){
            int max_element2 = pq.top();
            andTreePath = max_element1 + max_element2 + weight[node];
            // Check which path to store in weight node
            if(singlePath > andTreePath){
                weight[node] = singlePath;
                modified = true;
            }
            else{
                weight[node] = andTreePath;
                modified = true;
            }
        }
        // Check which path to store in weight node if not modified
        if(!modified){
            if(singlePath > weight[node]){
                weight[node] = singlePath;
            }
        }
        // Update Max Sum if needed
        maxSum = (maxSum < weight[node])? weight[node] : maxSum;
        
        // Return a single path
        return singlePath;
    }
    // We have no child nodes/ this is a leaf node
    else{
        return weight[node];
    }
}
int findMaxSum(vector<vector<int>> &adj_list, int node, vector<int> &weight) {
    // Initialize result
    int maxSum = weight[node];
    
    // Compute and return result
    findMaxSumPath(adj_list, 0, weight, maxSum);

    return maxSum;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Number of nodes
    int n;
    cin >> n;
    
    // Vector to hold weight
    vector<int> weight(n);
    // Linked list to hold tree
    vector<vector<int>> adjList(n);
    
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    int parent_Input;
    vector<int> parent(n);
    parent[0]=-1;
    for(int i = 1; i < n; i++){
        cin >> parent_Input;
        adjList[parent_Input].push_back(i);
        parent[i]=parent_Input;
    }
    
    //print_List(adjList, parent);
    
    // pass all vectors to funtion
    cout << findMaxSum(adjList, 0, weight) << endl;
    return 0;
}
