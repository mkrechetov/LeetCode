#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
  unordered_map<int, bool> coloring;
  vector<bool> visited(graph.size(), false);
  bool curr_part = true;

  set<int> gen, nextgen; gen.insert(0);
  while (true) {
    cout << "Current generation:" << endl;
    for (int node: gen) {cout << node << ", ";}
    cout << endl;

    nextgen.clear();
    for (int node: gen) {
      visited[node] = true;
      coloring[node] = curr_part;
      cout << "Visited " << node << " and colored it " << curr_part << endl;

      for (int neigh: graph[node]) {
        if (visited[neigh]) {
          if (coloring[neigh] == curr_part) {
            cout << "contradiction in neighbor " << neigh << " of a node " << node <<endl;
            return false;
          }
        } else {
          nextgen.insert(neigh);
        }
      }
    }

    curr_part = !curr_part;

    if (nextgen.size() == 0) {
      for (int i=0;i<graph.size();i++) {
        if (!visited[i]) { nextgen.insert(i); break;}
      }
      if (nextgen.size() == 1) { gen=nextgen; continue; }
      else { break; }
    }
    else {
      gen = nextgen;
    }
  }
  return true;
}

int main() {
  // vector<vector<int>> graph = {vector<int>{1,2,3},vector<int>{0,2},vector<int>{0,1,3}};
  // cout << isBipartite(graph) << endl;


  // vector<vector<int>> graph = {vector<int>{1,3},vector<int>{0,2},vector<int>{1,3},vector<int>{0,2}};
  // cout << isBipartite(graph) << endl;

  vector<vector<int>> graph = {vector<int>{4},vector<int>{},vector<int>{4},vector<int>{4},vector<int>{0,2,3}};
  cout << isBipartite(graph) << endl;
}
