//
//  main.cpp
//  B. Feeding Friendsy
//
//  Created by Majd on 3/5/23.
//

#include <iostream>
#include <vector>

using namespace std;

int active(auto &range, int element){
    if(element >= range.first && element <= range.second.first){
        
        return (range.second.second == 0)? 1 : 3;
    }
    else{
        return 0;
    }
    
}
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Take input
    int T, n, m;
    cin >> T >> n >> m ;
    
    vector<pair<int, pair<int, int>>> upper_set;
    vector<pair<int, pair<int, int>>> lower_set;
    
    // Input upper
    int a, b, c;
    for(int it = 0; it < n; it++){
        cin >> a >> b >> c;
        upper_set.push_back(make_pair(a,make_pair(b,c)));
    }
    
    // Input lower
    for(int it = 0; it < m; it++){
        cin >> a >> b >> c;
        lower_set.push_back(make_pair(a,make_pair(b,c)));
    }
    
    // Find start and finish
    int upper_start;
    int upper_end;
    int lower_start;
    int lower_end;
    if(!upper_set.empty()){
        upper_start = upper_set[0].first;
        upper_end = upper_set[upper_set.size()-1].second.first;
    }
    if(!lower_set.empty()){
        lower_start = lower_set[0].first;;
        lower_end = lower_set[lower_set.size()-1].second.first;
    }
    int result = 0;
    int u_index = 0;
    int l_index = 0;

    for(int it = min(upper_start, lower_start); it <= max(upper_end, lower_end); it++){
        
        auto upper_pointer = upper_set[u_index];
        auto lower_pointer = lower_set[l_index];
        
        int active_in_upper = active(upper_pointer, it);
        int active_in_lower = active(lower_pointer, it);
        
        if(it == upper_pointer.second.first){
            u_index++;
        }
        if(it == lower_pointer.second.first){
            l_index++;
        }
        
        if(active_in_upper==0&&active_in_lower==0 && it < min(upper_pointer.first, lower_pointer.first)){
            it = min(upper_pointer.first, lower_pointer.first) -1;
        }
        
        result+=max(active_in_upper, active_in_lower);

    }
    cout << result << endl;
    return 0;
}
