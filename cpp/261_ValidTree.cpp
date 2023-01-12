#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, set<int>> inc;
    for (int i=0; i<n; i++) {inc[i] = set<int>();}
    for (auto e: edges) { inc[e[0]].insert(e[1]); inc[e[1]].insert(e[0]); }

    queue<int> q; q.push(0);
    set<int> observed;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (observed.find(curr) != observed.end()) {
          return false;
        } else {
          for (int neigh: inc[curr]) { q.push(neigh); inc[neigh].erase(curr);}
        }
        observed.insert(curr);
    }

    if (observed.size() == n) {return true;}
    else {return false;}
}

int main() {

  int n = 5;
  vector<vector<int>> edges = {vector<int>{0,1},vector<int>{0,2},
                               vector<int>{0,3},vector<int>{1,4}};
  cout << validTree(n, edges) << endl;

  edges = {vector<int>{0,1},vector<int>{1,2}, vector<int>{2,3},vector<int>{1,3},
           vector<int>{1,4}};
  cout << validTree(n, edges) << endl;

}
