//
//  main.cpp
//  C. Bookshelf
//
//  Created by Majd on 3/9/23.
//

#include <iostream>
#include <vector>

using namespace std;

bool does_fit(vector<int> &books, int width, int k){
    int currentWidth = 0;
    int slots = 1;
    bool return_val = true;
    for (int it = 0; it < books.size(); it++) {
        if (books[it] > width){
            return_val = false;
            break;
        }
        if (currentWidth + books[it] <= width) {
            currentWidth += books[it];
        } else {
            currentWidth = books[it];
            slots++;
        }
        if (slots > k){
            return_val = false;
            break;
        }
    }
    return return_val;
}

int binarySearch(vector<int> &books, int k, int l, int r) {
    int left = l;
    int right = r;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if(does_fit(books, mid, k)){
            right = mid;
        }
        else{
            left = mid+1;
        }
        if(left == right){
            return left;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Take input
    int n, k;
    cin >> n >> k ;
    
    vector<int> books(n);
    
    int min = 0;
    int max = 0;
    
    int input;
    
    for(int it = 0; it < n; it++){
        cin >> input;
        books.push_back(input);
        min = (input>min)? input: min;
        max += input;
    }

    cout << binarySearch(books, k, min, max) << endl;

    return 0;
}
