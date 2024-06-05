//
//  main.cpp
//  A. Wizard Chess
//
//  Created by Majd on 2/19/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int get_Char_Board_Value(char letter){
    int num_Corr = 9;
    switch (letter) {
        case 'a': num_Corr = 0;
            break;
        case 'b': num_Corr = 1;
            break;
        case 'c': num_Corr = 2;
            break;
        case 'd': num_Corr = 3;
            break;
        case 'e': num_Corr = 4;
            break;
        case 'f': num_Corr = 5;
            break;
        case 'g': num_Corr = 6;
            break;
        case 'h': num_Corr = 7;
            break;
    }
    return num_Corr;
}

bool can_Move(pair<int,int> current_Coor, pair<int,int> dest_Coor){
    int i_Res = current_Coor.first+dest_Coor.first;
    int j_Res = current_Coor.second+dest_Coor.second;
    // If move is in bound
    if((i_Res >= 0 && i_Res < 8)&&(j_Res >= 0 && j_Res < 8)){
        return true;
    }
    else{
        return false;
    }
}

pair<int,int> get_Next_Pos(pair<int,int> current_Coor, pair<int,int> dest_Coor){
    int i_Res = current_Coor.first+dest_Coor.first;
    int j_Res = current_Coor.second+dest_Coor.second;
    return pair(i_Res, j_Res);
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Board counter
    int counter = 1;
    
    // Number of spots taken
    int spots_Taken;
    
    while (cin >> spots_Taken){
        
        if (spots_Taken == -1) {
            break;
        }
        // Board 2D matrix
        vector<vector<int>> board(8, vector<int>(8, 0));
        
        // Input Spots
        for(int it = 0; it < spots_Taken; it++){
            string input;
            cin >> input;
            int i = int(input.at(1) - 48) -1;
            // check edge case in case >9 or <0
            // Translate
            int j = get_Char_Board_Value(input[0]);
            board[i][j] = -1;
        }
        queue<pair<pair<int,int>,int>> queue_Corr;
        for(int it = 0; it < 2; it++){
            string input;
            cin >> input;
            int i = int(input.at(1) - 48) -1;
            // check edge case in case >9 or <0
            int j = get_Char_Board_Value(input[0]);
            if(it == 0){
                board[i][j] = -5;
                queue_Corr.push(pair(pair(i,j),0));
            }
            else{
                board[i][j] = 65;
            }
        }
        vector<int> moves_to_des;
        bool found = false;
        // BFS
        while (!queue_Corr.empty()) {
            // Possible moves
            vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, 1}, {2, -1}, {1, 2}, {-1, -2}};
            // Hold our current position
            pair<pair<int,int>,int> current_Pos = queue_Corr.front();
            // Remove front
            queue_Corr.pop();
            // Add all possible moves
            for(int it = 0; it < moves.size(); it++){
                // If knight can move
                bool can_Move_Coor = can_Move(pair(current_Pos.first.first, current_Pos.first.second), pair(moves[it][0], moves[it][1]));
                if (can_Move_Coor) {
                    pair<int,int> next_Pos = get_Next_Pos(pair(current_Pos.first.first, current_Pos.first.second),pair(moves[it][0], moves[it][1]));
                    // Check if pos is empty
                    if(board[next_Pos.first][next_Pos.second]==0){
                        // Move
                        board[next_Pos.first][next_Pos.second]= current_Pos.second + 1;
                        if(!found){
                            queue_Corr.push(pair(next_Pos,current_Pos.second+1));
                        }
                    }
                    else{
                        if(board[next_Pos.first][next_Pos.second]==65){
                            //Stop and return found
                            found = true;
                            moves_to_des.push_back(current_Pos.second + 1);
                        }
                    }
                }
            }
            
        }
        
        if(!moves_to_des.empty()){
            int final_Res = *min_element(moves_to_des.begin(), moves_to_des.end());
            cout << "Board " << counter << ": " << final_Res << " moves" << endl;
        }
        else{
            cout << "Board " << counter << ": not reachable" << endl;
            
        }
        counter++;
    }
    return 0;
}
