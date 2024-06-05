//
//  main.cpp
//  D. Black Family Tree
//
//  Created by Majd on 1/11/23.
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
void print_Roots(vector<int> &roots){

    for (int i = 0; i < roots.size(); i++){
        cout << "[" << roots.at(i) << "] ";
    }
    cout << endl;
}
int count_Nodes(vector<vector<int>> &adj_list, int root){
    int count = 1;
    queue<int> node_Queue;
    node_Queue.push(root);
    
    while (!node_Queue.empty()) {
        int node = node_Queue.front();
        for(int i = 0; i < adj_list[node].size(); i++){
            node_Queue.push(adj_list[node][i]);
            count++;
        }
        node_Queue.pop();
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Number of People / Traitors
    int n, m;
    cin >> n;
    cin >> m;
    
    
    // All roots
    vector<int> roots;
    
    // Push in original root
    roots.push_back(0);
    
    // Linked list to hold family tree
    vector<vector<int>> adj_list(n);
    
    // All nodes are roots at first
    vector<int> parent_Node(n,-1);
    
    // Push all the nodes
    int parent_Input;
    for(int i = 1; i < n; i++){
        cin >> parent_Input;
        if(parent_Input != i){
            adj_list[parent_Input].push_back(i);
            parent_Node[i] = parent_Input;
        }
        // Check if node is assigned
        // it's own value as parent
        else{
            roots.push_back(i);
        }
    }
    
    //print_List(adj_list, parent_Node);
    
    // Input & Delete traitors from list
    int traitor_Input;
    for(int i = 0; i < m; i++){
        
        // Input Traitor
        cin >> traitor_Input;
        
        if(traitor_Input != 0){
            
            // Update childs Nodes

            for (int j = 0; j < adj_list[traitor_Input].size(); j++) {
                parent_Node[adj_list[traitor_Input][j]] = -1;
                roots.push_back(adj_list[traitor_Input][j]);
            }
            
            int traitor_Parent = parent_Node[traitor_Input];
            
            // if parent node
            if(traitor_Parent >= 0){
                //delete from parent
                adj_list[traitor_Parent].erase(remove(adj_list[traitor_Parent].begin(), adj_list[traitor_Parent].end(), traitor_Input), adj_list[traitor_Parent].end());
                parent_Node[traitor_Input] = -5;
                adj_list[traitor_Input].clear();
            }
            else{
                parent_Node[traitor_Input] = -5;
                adj_list[traitor_Input].clear();
                roots.erase(remove(roots.begin(), roots.end(), traitor_Input), roots.end());
            }
        }
        // Remove root 0
        else{
            // Update childs Nodes
            for (int j = 0; j < adj_list[traitor_Input].size(); j++) {
                parent_Node[adj_list[traitor_Input][j]] = -1;
            }
            parent_Node[traitor_Input] = -5;
            adj_list[traitor_Input].clear();
            roots.erase(remove(roots.begin(), roots.end(), 0), roots.end());
        }
    }
    
    //print_List(adj_list, parent_Node);

    vector<int> node_Count;
    for(int i = 0; i < roots.size() ; i++){
        node_Count.push_back(count_Nodes(adj_list, roots.at(i)));
    }
    
    if(node_Count.size()>0){
        cout << *max_element(node_Count.begin(), node_Count.end());
    }
    else{
        cout << 0;
    }
    
    return 0;
}
