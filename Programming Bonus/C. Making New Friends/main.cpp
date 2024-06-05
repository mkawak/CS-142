//
//  main.cpp
//  C. Making New Friends
//
//  Created by Majd on 2/27/23.
//

#include <iostream>
#include <vector>

using namespace std;

// Create pairs as a key for maps
typedef std::pair<int, int> pair_int;

// Print grid
void print_Grid(vector<vector<pair<int, int>>> &grid){
    
    cout << "---------------------- " << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.at(i).size(); j++) {
            cout << "(" << grid[i][j].first << ", " << grid[i][j].second << ")  ";
        }
        cout << endl;
    }
    cout << "---------------------- " << endl;
}
// Print edges
void print_Edges(vector<pair<pair_int, int>> &edge_Map){
    int edge = 1;
    cout << "---------------------- " << endl;
    for (auto it = edge_Map.begin(); it != edge_Map.end(); it++){
        cout << "Edge " << edge << " Value " << it->second << " (" << it->first.first << ", " << it->first.second << ")" << endl;
        edge++;
    }
    cout << "---------------------- " << endl;
}
// Function to sort
bool compare_sort_helper(pair<pair_int, int>& a, pair<pair_int, int>& b){
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}
// Unionfind
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
// Check boundaries
bool move(int i, int j , int rowsNum, int colunmsNum, char direction){
    
    switch (direction) {
        case 'U':
            if(i > 0){
                return true;
            }
            else{
                return false;
            }
        case 'D':
            if(i < rowsNum - 1){
                return true;
            }
            else{
                return false;
            }
        case 'L':
            if(j < colunmsNum - 1){
                return true;
            }
            else{
                return false;
            }
        case 'R':
            if(j > 0){
                return true;
            }
            else{
                return false;
            }
        default:
            return false;
    }
}
// Compute all edges in matrix
void compute_Edges(vector<pair<pair_int, int>> &edge_Map, vector<vector<pair<int, int>>> &grid_Map, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(move(i,j,rows,cols,'D')){
                int min_val = min(grid_Map[i][j].second,grid_Map[i+1][j].second);
                edge_Map.push_back(make_pair(make_pair(grid_Map[i][j].first, grid_Map[i+1][j].first),min_val));
            }
            if(move(i,j,rows,cols,'L')){
                int min_val = min(grid_Map[i][j].second,grid_Map[i][j+1].second);
                edge_Map.push_back(make_pair(make_pair(grid_Map[i][j].first, grid_Map[i][j+1].first),min_val));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    // Number of rows and columns
    int rows, cols;
    cin >> rows >> cols;
    
    // Union find
    UnionFind uf(rows*cols);
    
    // Map of students (Number, Value)
    vector<vector<pair<int, int>>> grid_Map(rows, vector<pair<int, int>>(cols, make_pair(0, 0)));
    
    // Chat value at coordinate (i, j)
    vector<pair<pair_int, int>> edge_Map;
    
    int counter = 0;
    
    // Take input
    int value;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> value;
            grid_Map[i][j]=make_pair(counter++, value);
        }
    }
    
    //print_Grid(grid_Map);

    compute_Edges(edge_Map, grid_Map, rows, cols);
    
    //print_Edges(edge_Map);
    
    sort(edge_Map.begin(), edge_Map.end(), compare_sort_helper);
    
    //print_Edges(edge_Map);
    
    int total_Candies = 0;
    
    //int round = 1;
    
    for (auto it = edge_Map.begin(); it != edge_Map.end(); it++){
        int chat_Cost = it->second;
        
        // Node number
        int x = it->first.first;
        int y = it->first.second;
        
        if(uf.find(x)!=uf.find(y)){
            uf.unite(x,y);
            total_Candies+=chat_Cost;
        }
        /*
        cout << "------ROUND " << round << "----------- " << endl;
        // find the connected components
        std::vector<std::vector<int>> components(rows*cols);
        for (int i = 0; i < rows*cols; i++) {
            components[uf.find(i)].push_back(i);
        }

        // print the connected components
        for (auto component : components) {
            if (!component.empty()) {
                std::cout << "Connected component: ";
                for (auto node : component) {
                    std::cout << node << " ";
                }
                std::cout << std::endl;
            }
        }
        round++;
        */
    }
    cout << total_Candies << endl;
    
    return 0;
}
