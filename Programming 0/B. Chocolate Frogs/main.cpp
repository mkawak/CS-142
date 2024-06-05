//
//  main.cpp
//  B. Chocolate Frogs
//
//  Created by Majd on 1/11/23.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    
    cin >> n;
    
    map <int, int> map;
    
    int key;
    
    for (int i = 0; i < n; i++){
        cin >> key;
        int temp = map[key];
        temp ++;
        map[key] = temp;
    }
    for (auto const &pair: map) {
        cout << pair.first << " " << pair.second << "\n";
    }
}
