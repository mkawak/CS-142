//
//  main.cpp
//  D. Disneyland
//
//  Created by Majd on 3/9/23.
//

#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

Point p0;

Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
    (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);
    
    if (val == 0) return 0; // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    
    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
    
    return (o == 2)? -1: 1;
}
double calculateArea(vector<Point> &points) {
    double area = 0;
    int n = points.size();
    
    // Calculate the area using the Shoelace formula
    for (int i = 0; i < n; i++) {
        area += points[i].x * points[(i + 1) % n].y;
        area -= points[i].y * points[(i + 1) % n].x;
    }
    
    area = abs(area) / 2;
    
    return area;
}

void convexHull(vector<Point> &points, int n){

    int ymin = points[0].y, min = 0;
    
    for (int i = 1; i < n; i++){
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)){
            ymin = points[i].y, min = i;
        }
    }
    swap(points[0], points[min]);

    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++){
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0){
            i++;
        }
        points[m] = points[i];
        m++; // Update size of modified array
    }
    
    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3) {
        double output = 0;
        cout << fixed << setprecision(6) << output << endl;
        return;
    }
    // Create an empty stack and push first three points
    // to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    
    // Process remaining n-3 points
    for (int i = 3; i < m; i++){
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2) {
            S.pop();
        }
        S.push(points[i]);
    }
    vector<Point> result;
    // Now stack has the output points, print contents of stack
    while (!S.empty()){
        Point p = S.top();
        result.push_back(p);
        S.pop();
    }
    cout << fixed << setprecision(6) << calculateArea(result) << endl;
}

// Driver program to test above functions
int main(int argc, const char * argv[]) {
    
    vector<Point> points;
    for(int it = 0; it < 4; it++){
        Point input;
        cin>> input.x >> input.y;
        points.push_back(input);
    }
    convexHull(points, 4);
    return 0;
}

