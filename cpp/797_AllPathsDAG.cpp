#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

void print(vector<vector<int>> result) {
  for (auto path: result) {
    for (int node: path) {cout << node << " -> ";}
    cout << endl;
  }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
  vector<vector<int>> result;

  queue<vector<int>> q;
  q.push(vector<int>{0});
  while (!q.empty()) {
    vector<int> currpath = q.front(); q.pop();
    for (int neigh: graph[currpath.back()]) {
      vector<int> nextpath = currpath;
      nextpath.push_back(neigh);
      if (neigh == graph.size()-1) {
        result.push_back(nextpath);
      } else {
        q.push(nextpath);
      }
    }
  }

  return result;
}

int main() {

  vector<vector<int>> edges = {vector<int>{1,2},vector<int>{3},
                               vector<int>{3},vector<int>{},};
  print(allPathsSourceTarget(edges));
}
