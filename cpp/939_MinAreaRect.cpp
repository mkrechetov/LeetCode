#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>

#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& p) {
  cout << "{" << p[0] << "," << p[1] << "}" << endl;
}
string pstr(vector<int>& p){
    return to_string(p[0])+","+to_string(p[1]);
}

int area(vector<int>& p1, vector<int>& p2) {
    return (abs(p1[0]-p2[0])*abs(p1[1]-p2[1]));
}

int minAreaRect(vector<vector<int>>& points) {
    // unordered_map<string, bool> observed;
    // for (auto p: points) { observed[pstr(p)] = true; cout << pstr(p) << ", ";}
    // cout << endl;
    // for (auto p: points) {cout << observed[pstr(p)];} cout << endl;

    unordered_map<int, unordered_set<int>> h;
    for (auto p: points) {h[p[0]] = unordered_set<int>();}
    for (auto p: points) {h[p[0]].insert(p[1]);}

    int minArea = INT_MAX;
    bool find_any = false;
    for (int i=0;i<points.size();i++) {
        vector<int> p1 = points[i];
        for (int j=i+1;j<points.size();j++) {
            vector<int> p2 = points[j];
            if ((p1[0] != p2[0]) && (p1[1] != p2[1])) {
                // print(p1); print(p2); cout << endl;
                vector<int> p4{p2[0], p1[1]};
                if (h[p1[0]].find(p2[1])!=h[p1[0]].end()) {
                    if (h[p2[0]].find(p1[1])!=h[p2[0]].end()) {
                      print(p1); print(p2); cout << endl;
                      find_any = true;
                      if (area(p1,p2) < minArea) {minArea = area(p1,p2);}
                    }
                }
            }
        }
    }
    if (find_any) {return minArea;}
    else {return 0;}
}

int main() {
  vector<vector<int>> points{vector<int>{1,1}, vector<int>{1,3}, vector<int>{3,1},
                             vector<int>{3,3}, vector<int>{2,2}};
  cout << minAreaRect(points) << endl;

  points = vector<vector<int>>{vector<int>{0,1}, vector<int>{1,3},
                               vector<int>{3,3},vector<int>{4,4},
                               vector<int>{1,4}, vector<int>{2,3},
                               vector<int>{1,0},vector<int>{3,4},};
  cout << minAreaRect(points) << endl;


  return 1;
}
