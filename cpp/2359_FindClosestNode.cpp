#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
  if (node1 == node2) {return node1;}
  // else if (edges[node1] == node2) {return node2;}
  // else if (edges[node2] == node1) {return node1;}

  int n = edges.size();

  unordered_map<int,int> node1_dist, node2_dist;
  for (int i=0;i<n;i++) { node1_dist[i] = -1; node2_dist[i] = -1; }
  node1_dist[node1] = 0; node2_dist[node2] = 0;

  vector<bool> visited1(n, false);
  vector<bool> visited2(n, false);
  queue<int> q1; q1.push(node1);
  queue<int> q2; q2.push(node2);

  while (true) {
      if (!q1.empty()) {
          int q1_node = q1.front(); q1.pop();
          visited1[q1_node] = true;
          int q1_neigh = edges[q1_node];
          if (q1_neigh != -1) {
              if (!visited1[q1_neigh]) {
                  q1.push(q1_neigh);
                  node1_dist[q1_neigh] = node1_dist[q1_node]+1;
                  // if (node2_dist[q1_neigh] != -1) {return q1_neigh;}
              }
          }
      }

      if (!q2.empty()) {
          int q2_node = q2.front(); q2.pop(); visited2[q2_node] = true;
          int q2_neigh = edges[q2_node];
          if (q2_neigh != -1) {
              if (!visited2[q2_neigh]) {
                  q2.push(q2_neigh);
                  node2_dist[q2_neigh] = node2_dist[q2_node]+1;
                  // if (node1_dist[q2_neigh] != -1) {return q2_neigh;}
              }
          }
      }

      if ((q1.empty()) && (q2.empty())) {break;}
  }

  int closest_dist = n+1;
  int closest_node = -1;
  for (int i=n-1;i>=0;i--) {
      cout << i << ":" << node1_dist[i] << ", " << node2_dist[i] <<endl;
      if ((node1_dist[i] != -1) and (node2_dist[i] != -1)) {
          int max;
          if (node1_dist[i] >= node2_dist[i]) {
              max = node1_dist[i];
          } else {
              max = node2_dist[i];
          }
          if (max <= closest_dist) {
              closest_dist = max;
              closest_node = i;
          }
      }
  }

  return closest_node;

}

int main() {

  // vector<int> edges{2,2,3,-1};
  // cout << closestMeetingNode(edges, 0, 1) << endl;
  //
  //
  // edges = vector<int> {1,2,-1};
  // cout << closestMeetingNode(edges, 0, 2) << endl;


  vector<int> edges = {1, 0};
  cout << closestMeetingNode(edges, 0, 1) << endl;

}
