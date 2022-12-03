#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

typedef vector<string> board;

void display(board b){
  int n = b.size();
  for (int row=0; row<n; row++) {
    for (int col=0; col<n; col++) {
      cout << b[row][col];
    }
    cout << endl;
  }
  cout << endl;
}

board convert(vector<int> pos) {
  board result;
  int n = pos.size();

  for (int i=0; i<n; i++) { result.push_back(string(n, '.')); }
  for (int i=0; i<n; i++) {
    result[pos[i]][i] = 'Q';
  }
  return result;
}

bool check(vector<int> pos) {
  int n = pos.size();
  int count = 0;

  // main
  for (int col=0; col<n; col++) {
    if (pos[col] == col) { count += 1; }
  }
  if (count >= 2) {return false;}

  // upper main
  for (int main=1; main <= n-2; main++) {
    count = 0;
    for (int col=main; col<n; col++) {
      if (pos[col] == col - main) { count += 1; }
    }
    if (count >= 2) {return false;}
  }

  // lower main
  for (int main=1; main <= n-2; main++) {
    count = 0;
    for (int col=0; col<n-main; col++) {
      if (pos[col] == col + main) { count += 1; }
    }
    if (count >= 2) {return false;}
  }

  // skew
  count = 0;
  for (int col=0; col<n; col++) {
    if (pos[col] == n-col-1) { count += 1; }
  }
  if (count >= 2) {return false;}

  // upper skew
  for (int skew=1; skew <= n-2; skew++) {
    count = 0;
    for (int col=0; col<=n-1-skew; col++) {
      if (pos[col] == n-1-col-skew) { count += 1; }
    }
    if (count >= 2) {return false;}
  }

  // lower skew
  for (int skew=1; skew <= n-2; skew++) {
    count = 0;
    for (int col=skew; col<=n-1; col++) {
      if (pos[col] == n-1-col+skew) { count += 1; }
    }
    if (count >= 2) {return false;}
  }
  return true;
}

vector<board> solveNQueens(int n) {
  vector<int> pos;
  for (int i=0; i<n; i++) { pos.push_back(i); }

  vector<board> result;
  do{
    if (check(pos)) {
      result.push_back(convert(pos));
    }
   } while (next_permutation(pos.begin(), pos.end()));

   return result;
}



int main(int argc, char* argv[]) {

  auto result = solveNQueens(9);
  cout << "Nsol = " << result.size() << endl;
  // for (board b: result) {display(b);}

  return 1;
}
