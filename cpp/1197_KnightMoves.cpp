#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> next(set<pair<int, int>> generation) {
  set<pair<int, int>> result;

  for (pair<int, int> pos: generation) {
      result.insert(make_pair(pos.first+1, pos.second+2));
      result.insert(make_pair(pos.first+2, pos.second+1));
      result.insert(make_pair(pos.first+2, pos.second-1));
      result.insert(make_pair(pos.first+1, pos.second-2));
      result.insert(make_pair(pos.first-1, pos.second-2));
      result.insert(make_pair(pos.first-2, pos.second-1));
      result.insert(make_pair(pos.first-2, pos.second+1));
      result.insert(make_pair(pos.first-1, pos.second+2));
  }

  return result;
}

set<pair<int, int>> filter(set<pair<int, int>> generation, pair<int,int> targ) {

  int l2 = targ.first*targ.first+targ.second*targ.second;
  pair<int, int> closest;

  for (auto pos: generation) {
    int a = (pos.first-targ.first)*(pos.first-targ.first);
    int b = (pos.second-targ.second)*(pos.second-targ.second);
    if (a+b < l2) { l2 = a+b; closest = pos;}
  }

  if (l2 <= 9) { return generation; }
  else {
    set<pair<int, int>> result;
    result.insert(closest);
    return result;
  }
}

int minKnightMoves(int x, int y) {
  if ((x==0) && (y==0)) { return 0; }
  else {
    x = abs(x); y = abs(y);

    set<pair<int, int>> generation;
    int counter = 1;
    pair<int, int> zero = make_pair(0, 0);
    pair<int, int> targ = make_pair(x, y);
    generation.insert(zero);

    while (true) {
        set<pair<int, int>> nextgen = next(generation);
        generation = filter(nextgen, targ);
        if (generation.find(targ) != generation.end()) {
          return counter;
        }
        counter++;
    }
  }
}

int main(){

  cout << minKnightMoves(0, 0) << endl;
  cout << minKnightMoves(0, 1) << endl;
  cout << minKnightMoves(1, 1) << endl;
  cout << minKnightMoves(1, 0) << endl;
  cout << minKnightMoves(1, -1) << endl;
  cout << minKnightMoves(0, -1) << endl;
  cout << minKnightMoves(-1, -1) << endl;
  cout << minKnightMoves(-1, 0) << endl;
  cout << minKnightMoves(-1, 1) << endl;


  cout << "For 270,-21 got " << minKnightMoves(270, -21) << ", expected 135." << endl;

  return 0;
}
