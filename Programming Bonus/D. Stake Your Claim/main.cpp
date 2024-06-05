//
//  main.cpp
//  D. Stake Your Claim
//
//  Created by Majd on 3/16/23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> section_count(5, 0);

void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int color) {
    visited[i][j] = true;
    matrix[i][j] = color;
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    if (i > 0 && matrix[i-1][j] != 0 && !visited[i-1][j]) {
        dfs(matrix, visited, i-1, j, color);
    }
    if (i < n-1 && matrix[i+1][j] != 0 && !visited[i+1][j]) {
        dfs(matrix, visited, i+1, j, color);
    }
    if (j > 0 && matrix[i][j-1] != 0 && !visited[i][j-1]) {
        dfs(matrix, visited, i, j-1, color);
    }
    if (j < m-1 && matrix[i][j+1] != 0 && !visited[i][j+1]) {
        dfs(matrix, visited, i, j+1, color);
    }
}

void color_matrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int section = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && matrix[i][j] != 0) {
                dfs(matrix, visited, i, j, section);
                section++;
            }
        }
    }
}
void print_matrix(vector<vector<int>> &matrix) {
    cout << "-------------------" << endl;
    for (auto row : matrix) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}
void count_odds(vector<vector<int>> &matrix) {

    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int i = 1; i < n; i += 2) {
        for (int j = 1; j < m; j += 2) {
            if (matrix[i][j] != 0) {
                section_count[matrix[i][j]]++;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {

    int r,c;
    cin >> r >> c;
    r = (r*2)+1;
    c = (c*2)+1;
    
    vector<vector<int>> matrix (r, vector<int>(c));
    char input_char;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> input_char;
            if(input_char == '.'){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
    //print_matrix(matrix);
    color_matrix(matrix);
    //print_matrix(matrix);
    count_odds(matrix);
    sort(section_count.begin(), section_count.end());
    for (int i = section_count.size()-1; i > 0; i--) {
        cout << section_count[i] << " ";
    }
    cout << endl;

    return 0;
}

