#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void print(set<string> route) {
  cout << "[";
  for (string city: route) {cout << city << ", ";}
  cout << "]\n";
}

string crackSafe(int n, int k) {
  if (n==1) {
    string result = "";
    for (int i=0;i<k;i++) {result += to_string(i);}
    return result;
  } else {
    set<string> nodes;
    for (int i=0;i<k;i++) {nodes.insert(to_string(i));}
    for (int d=1;d<n;d++) {
      set<string> nextnodes;
      for (string node: nodes) {
        for (int i=0;i<k;i++) {
          nextnodes.insert(node + to_string(i));
        }
      }
      nodes = nextnodes;
    }

    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> visited;
    for (string node: nodes) {
      adj[node] = vector<string>();
      visited[node] = false;
      string begin = node;
      begin.erase(0, 1);
      for (int i=0;i<k;i++) { adj[node].push_back(begin + to_string(i)); }
    }


    string result = *nodes.begin();
    string curr = result;
    for (int i=1;i<nodes.size(); i++) {
      visited[curr] = true;
      while (visited[adj[curr].back()]) {adj[curr].pop_back();}
      string nxt = adj[curr].back(); adj[curr].pop_back();
      result += nxt.back();
      curr = nxt;
    }
    return result;
  }
}


int main(){

  cout << crackSafe(1, 2) << endl;
  cout << crackSafe(2, 2) << endl;
  return 1;
}
