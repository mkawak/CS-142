//
//  main.cpp
//  F. Broomstick
//
//  Created by Majd on 3/12/23.
//
 
#include <iostream>
#include <vector>
#include <map>
 
using namespace std;

double cal_dis(double first, double second){
    if((first <= 0 && second <= 0) || (first >= 0 && second >= 0)){
        return abs(first-second);
    }
    else{
        return abs(first) + abs(second);
    }
}
 
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    map<int, vector<int>> map_list;
    
    int n;
    cin >> n;
    
    int dir;
    cin >> dir;
    
    double d;
    
    if(dir == 90){
        cin >> d;
        int x;
        int y;
        for(int it = 0; it < n; it++){
            cin >> x >> y;
            map_list[x].push_back(y);
        }
        
    }
    else{
        cin >> d;
        int x;
        int y;
        for(int it = 0; it < n; it++){
            cin >> x >> y;
            map_list[y].push_back(x);
        }
    }
    
    d = d*2;
    
    int max = 0;
    for (map<int, vector<int>>::iterator it = map_list.begin(); it != map_list.end(); it++) {
        int result = it->second.size();
        map<int, vector<int>>::iterator next_it = ++it;
        it--;
        double distance = abs(it->first-next_it->first);
        while (distance <= d && distance > 0 && next_it!=map_list.end()) {
            result += next_it->second.size();
            next_it++;
            distance = abs(it->first-next_it->first);
        }
        max = (max < result)? result : max;
    }
     
    cout << max << endl;
    return 0;
}
