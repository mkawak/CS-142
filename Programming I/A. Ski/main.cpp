//
//  main.cpp
//  A. Ski
//
//  Created by Majd Kawak on 02/06/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_Path(vector<vector<int>>& matrix, vector<vector<int>>& matrix_To_Solve, int row, int col, int& m, int& n) {
    
    // Hold our longest path from point to itself
    int path = 1;
    
    //Hold our 4 possibilities paths
    int UP = 0, DOWN = 0, LEFT = 0, RIGHT = 0;
    
    // Can go UP?
    if (row > 0) {
        // Check if UP is smaller
        if (matrix[row][col] > matrix[row - 1][col]) {
            // Check if value already computed
            if(matrix_To_Solve[row - 1][col] == -1) {
                UP +=compute_Path(matrix, matrix_To_Solve, row - 1, col, m, n);
            }
            // Compute otherwise
            else{
                // Add current edges to UP point
                UP += matrix_To_Solve[row - 1][col];
            }
        }
    }
    // Can go DOWN?
    if (row < m - 1) // can check down
    {
        // Check if DOWN is smaller
        if (matrix[row][col] > matrix[row + 1][col]) {
            // Check if value already computed
            if(matrix_To_Solve[row + 1][col] == -1) {
                DOWN +=compute_Path(matrix, matrix_To_Solve, row + 1, col, m, n);
            }
            // Compute otherwise
            else{
                // Add current edges to DOWN point
                DOWN += matrix_To_Solve[row + 1][col];
            }
        }
    }
    // Can go LEFT?
    if (col > 0) {
        // Check if LEFT is smaller
        if (matrix[row][col] > matrix[row][col - 1]) {
            // Check if value already computed
            if(matrix_To_Solve[row][col - 1]==-1) {
                LEFT +=compute_Path(matrix, matrix_To_Solve, row, col-1, m, n);
            }
            // Compute otherwise
            else{
                // Add current edges to LEFT point
                LEFT += matrix_To_Solve[row][col - 1];
            }
        }
    }
    // Can go RIGHT?
    if (col < n - 1) {
        // Check if RIGHT is smaller
        if (matrix[row][col] > matrix[row][col + 1]) {
            // Check if value already computed
            if(matrix_To_Solve[row][col + 1] == -1) {
                RIGHT += compute_Path(matrix, matrix_To_Solve, row, col + 1, m, n);
            }
            // Compute otherwise
            else{
                // Add current edges to RIGHT point
                RIGHT += matrix_To_Solve[row][col+1];
            }
        }
    }
    
    int longest_Path = max({UP,DOWN,LEFT,RIGHT}) + path;
    matrix_To_Solve[row][col] = longest_Path;
    return matrix_To_Solve[row][col];
}
int main(int argc, const char * argv[]) {
    
    // Row Col of Matrix
    int row;
    int col;
    cin >> row;
    cin >> col;
    
    // Initialize 2d vector "Matix" size, all '0'
    vector<vector<int>> matrix(row, vector<int>(col));
    
    // Initialize 2d vector "Matix to Solve" size, all '-1' to check computed values
    vector<vector<int>> matrix_to_Solve(row, vector<int>(col, -1));
    
    // Populate 2D matrix
    int input_Height;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; j++) {

            cin >> input_Height;
            matrix[i][j] = input_Height;
        }
    }
    
    // Compute Longest Path
    int longest_Path = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; j++) {
            int temp = compute_Path(matrix, matrix_to_Solve, i, j, row, col);
            longest_Path = (temp>longest_Path)? temp: longest_Path;
        }
    }
    cout  <<  longest_Path;
    return 0;
}
