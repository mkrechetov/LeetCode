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

vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {

  // build adjacency list
  unordered_map<int, set<int>> adj;
  for (int i=0; i<n; i++) {adj[i] = set<int>();}
  for (auto e: edges) { adj[e[0]].insert(e[1]); adj[e[1]].insert(e[0]); }

  // if all vertices are of deg 2 -> there is a single cycle
  bool all_two = true;
  for (int i=0;i<n;i++) {if (adj[i].size()!=2) {all_two=false;break;}}
  if (all_two) {return vector<int>(n, 0);}

  // find a vertex with degree one to start DFS for cycle
  int deg_one = 0;
  while (adj[deg_one].size() != 1) {deg_one++;}

  // DFS
  vector<int> counter(n, 0);
  set<pair<int,int>> edge_visited;
  stack<int> st; st.push(deg_one);
  while (!st.empty()) {
      int node = st.top();
      counter[node]++;
      if (counter[node] == 2) {break;}

      int any_new_edge = false;
      for (int neigh: adj[node]) {
          int min, max;
          if (node < neigh) {min=node;max=neigh;}
          else {min=neigh;max=node;}

          if (edge_visited.find(make_pair(min, max))==edge_visited.end()) {
              st.push(neigh);
              any_new_edge = true;
              edge_visited.insert(make_pair(min, max));
              break;
          }
      }

      if (!any_new_edge) {st.pop();counter[st.top()]--;}
  }

  // extract the cycle from DFS result
  vector<int> path;
  while (!st.empty()) { path.push_back(st.top()); st.pop(); }
  vector<int> cycle; cycle.push_back(path[0]);
  int start = path[0];
  for (int i=1; i<path.size(); i++) {
      if (path[i]==start) {break;}
      else {cycle.push_back(path[i]);}
  }
  for (int i=0;i<cycle.size()-1;i++) {
      adj[cycle[i]].erase(cycle[i+1]);
      adj[cycle[i+1]].erase(cycle[i]);
  }
  adj[cycle[cycle.size()-1]].erase(cycle[0]);
  adj[cycle[0]].erase(cycle[cycle.size()-1]);


  // BFS from vertices of the cycle to find distances
  vector<int> result(n, 0);
  queue<int> q;
  for (int cycle_node: cycle) {
      if (adj[cycle_node].size() > 0) {
          vector<bool> visited(n, false);

          q = queue<int>();
          q.push(cycle_node);
          while (!q.empty()) {
              int node = q.front(); q.pop();
              visited[node] = true;
              for (int neigh: adj[node]) {
                  if ((!visited[neigh])) {
                      q.push(neigh);
                      result[neigh] = result[node] + 1;
                  }
              }
          }
      }
  }

  return result;
}

int main() {
  // int min, max;
  // int node=30; int neigh=25;
  // (node<neigh) ? min=node,max=neigh : min=neigh,max=node;
  vector<vector<int>> edges = {vector<int>{1,2},vector<int>{2,4},
                               vector<int>{4,3},vector<int>{3,1},
                              vector<int>{0,1},vector<int>{5,2},vector<int>{6,5},};
  print(distanceToCycle(7, edges));

  edges = vector<vector<int>>{vector<int>{2, 1},vector<int>{3,1},
                              vector<int>{2,0},vector<int>{4,2},
                              vector<int>{4,0}};
  print(distanceToCycle(5, edges));


  edges = vector<vector<int>>{vector<int>{4,3},vector<int>{2,3},
                              vector<int>{0,4},vector<int>{0,3},
                              vector<int>{1,4}};
  print(distanceToCycle(5, edges));
}
