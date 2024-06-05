//
//  main.cpp
//  A. Whomping Willow
//
//  Created by Majd on 1/11/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a, b, r, n;
    
    cin >> a;
    cin >> b;
    cin >> r;
    cin >> n;
    
    string v[n];
    
    int c, d;
    for (int i = 0; i < n; i++){
        cin >> c;
        cin >> d;
        if(sqrt(pow((a-c), 2)+pow((b-d), 2))>r){
            v[i] = "yes";
        }
        else{
            v[i] = "no";
        }
    }
    for (int i = 0; i < n; i++){
        cout << v[i] << "\n";
    }

    return 0;
}
