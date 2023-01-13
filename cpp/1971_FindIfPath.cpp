#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

bool validPathRec(int n, vector<vector<int>>& edges, int source, int destination) {
  vector<int> new_sources;

  vector<vector<int>>::iterator it = edges.begin();
  while(it!=edges.end()) {
    if ((*it)[0] == source) {
      if ((*it)[1] == destination) { return true; }
      else {
        new_sources.push_back((*it)[1]);
        it = edges.erase(it);
      }
    } else if ((*it)[1] == source) {
      if ((*it)[0] == destination) { return true; }
      else {
        new_sources.push_back((*it)[0]);
        it = edges.erase(it);
      }
    } else {
      ++it;
    }
  }

  for (int neigh: new_sources) {
    if (validPathRec(n-1, edges, neigh, destination)) { return true; }
  }

  return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
  if (n==1) {return true;}

  unordered_map<int, set<int>> inc;
  for (int i=0; i<n; i++) {inc[i] = set<int>();}
  for (auto e: edges) { inc[e[0]].insert(e[1]); inc[e[1]].insert(e[0]); }

  stack<int> q; q.push(source);
  vector<bool> visited(n, false);

  while (!q.empty()) {
      int curr = q.top(); q.pop();
      if (curr == destination) {return true;}
      else {
        visited[curr] = true;
        for (int neigh: inc[curr]) {
          if (!visited[neigh]) { q.push(neigh); }
        }
      }
  }

  return false;

}


int main() {

  int n = 3;
  vector<vector<int>> edges = {vector<int>{0,1},vector<int>{0,2},vector<int>{1,2}};
  cout << validPath(n, edges, 0, 2) << endl;


}
