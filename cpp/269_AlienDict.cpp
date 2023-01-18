#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

unordered_map<char, set<char>> build_dag(vector<string>& words){
  set<char> alphabet;
  for (int i=0;i<words.size();i++) {
    for (char c: words[i]) {alphabet.insert(c);}
  }

  unordered_map<char, set<char>> dag;
  for (char c: alphabet) {dag[c] = set<char>();}

  for (int i=0;i<words.size()-1;i++) {
    string l = words[i];
    string r = words[i+1];

    if (l!=r) {
      int pos = 0;
      while (l[pos] == r[pos]) {pos++;}
      if ((pos<l.size()) && (pos<r.size())) {dag[l[pos]].insert(r[pos]);}
      else if ((pos<l.size()) && (pos>=r.size())) {
        return unordered_map<char, set<char>>();
      }
    }
  }

  return dag;
}

set<char> find_roots(unordered_map<char, set<char>>& dag) {
  set<char> roots; for (auto e : dag) {roots.insert(e.first);}
  for (auto relation : dag) {
    for (char other_letter: relation.second) { roots.erase(other_letter); }
  }
  for (char root: roots) {dag.erase(root);}
  return roots;
}

vector<char> order(unordered_map<char, set<char>>& dag) {
  if (dag.size() == 0) {return vector<char>();}
  set<char> gen = find_roots(dag);
  if (gen.size() == 0) {return vector<char>();}
  vector<char> result;

  for (char letter: gen) {
    result.push_back(letter);
    dag.erase(letter);
  }

  vector<char> nextresult = order(dag);
  result.insert(result.end(), nextresult.begin(), nextresult.end());
  return result;

}

string alienOrder(vector<string>& words) {
  unordered_map<char, set<char>> dag = build_dag(words);
  int alphabet_size = dag.size();
  cout << "#Alph = " << alphabet_size << endl;
  vector<char> letter_order = order(dag);
  cout << "Order = " << string(letter_order.begin(), letter_order.end()) << endl;
  if (letter_order.size() != alphabet_size) {return "";}
  else { return string(letter_order.begin(), letter_order.end()); }
}

int main() {
  vector<string> words{"wrt","wrf","er","ett","rftt"};
  cout << alienOrder(words) << endl;

  words = vector<string>{"z","x"};
  cout << alienOrder(words) << endl;

  words = vector<string>{"z","x","z"};
  cout << alienOrder(words) << endl;

  words = vector<string>{"wrt","wrtkj"};
  cout << alienOrder(words) << endl;

  words = vector<string>{"abc","ab"};
  cout << alienOrder(words) << endl;

  // for (char c: alphabet) {cout << c;} cout << endl;

}
