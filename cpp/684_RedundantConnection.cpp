#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

void print(vector<int> result) {
  for (int node: result) {cout << node << ", ";}
  cout << endl;
}

vector<int> findCycle(vector<vector<int>>& edges) {
  int n = edges.size();

  unordered_map<int, set<int>> adj;
  for (int i=1;i<=n;i++) {adj[i] = set<int>();}
  for (auto e: edges) {adj[e[0]].insert(e[1]);adj[e[1]].insert(e[0]);}

  vector<bool> visited_node(n+1, false);
  stack<int> st; st.push(1);

  while (!st.empty()) {
      int node = st.top();
      visited_node[node] = true;

      if (adj[node].size() == 0) {st.pop();}
      else {
          bool looped = false;
          for (int neigh: adj[node]) {
              if (!visited_node[neigh]) {
                  st.push(neigh);
                  adj[node].erase(neigh);
                  adj[neigh].erase(node);
                  break;
              } else {
                  st.push(neigh);
                  looped = true;
                  break;
              }
          }
          if (looped) {break;}
      }
  }

  int start = st.top(); st.pop();
  vector<int> result{start};
  while (st.top() != start) {result.push_back(st.top()); st.pop();}

  return result;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

  vector<int> cycle = findCycle(edges);
  set<pair<int, int>> cycle_edges;
  for (int i=0;i<cycle.size()-1;i++) {
    cycle_edges.insert(make_pair(cycle[i], cycle[i+1]));
    cycle_edges.insert(make_pair(cycle[i+1], cycle[i]));
  }
  cycle_edges.insert(make_pair(cycle[0], cycle[cycle.size()-1]));
  cycle_edges.insert(make_pair(cycle[cycle.size()-1], cycle[0]));

  auto e = edges.back();
  while (cycle_edges.find(make_pair(e[0], e[1]))==cycle_edges.end()) {
      edges.pop_back();
      e = edges.back();
  }
  return e;
}

int main() {
  vector<vector<int>> edges = {vector<int>{1,2},vector<int>{1,3},
                               vector<int>{2,3},};
  print(findCycle(edges));
  print(findRedundantConnection(edges));
}
