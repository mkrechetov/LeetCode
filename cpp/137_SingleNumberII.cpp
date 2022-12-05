
#include <iostream>
#include <vector>
#include <list>
#include <assert.h>
#include <math.h>

using namespace std;

struct trit {
  bool a = false;
  bool b = false;

  inline trit operator=(trit t) { a=t.a; b=t.b; return t; }
  inline bool operator==(trit t) {
    if (t.a==a && t.b== b) return true;
    else return false;
  }
};

const trit trit0 = trit{false, false};
const trit trit1 = trit{false, true};
const trit trit2 = trit{true, false};
const trit tritF = trit{true, true};

trit operator+(trit t1, trit t2) {
  trit t = trit{};
  t.a = t1.a^t2.a^(t1.b && t2.b);
  t.b = t1.b^t2.b^(t1.a && t2.a);
  if (t == tritF) { return trit0; }
  else { return t; }
}

ostream& operator << (ostream& o, const trit t) {
    if ((t.a == false) && (t.b == false)) o << 0;
    else if ((t.a == false) && (t.b == true)) o << 1;
    else if ((t.a == true) && (t.b == false)) o << 2;
    else o << "*";
    return o;
}

const int ntrits = 30;

trit* ternary(int num) {
  static trit trits[ntrits];
  if (num < 0) { trits[0] = trit1;}
  else { trits[0] = trit2; }

  int r;
  for (int i=1; i<ntrits; i++) {
    r = abs(num % 3);
    if (r == 0) { trits[i] = trit0; }
    else if (r == 1) { trits[i] = trit1; }
    else { trits[i] = trit2; }
    num = num / 3;
  }
  return trits;
}

void print(trit* trits) {
  for (int i=0; i<ntrits; i++) { cout << trits[i]; }
  cout << endl;
}

void tritxor(trit* a, int num) {
  trit* b = ternary(num);
  for (int i=0; i<ntrits; i++) { a[i] = a[i] + b[i]; }
}

int from_trits(trit* t) {
  int result = 0;
  int sign = 1;

  if (t[0] == trit1) { sign = -1; }
  for (int i=1; i<ntrits; i++) {
    if (t[i] == trit2) {
      result += sign * 2 * pow(3, i-1);
    } else if (t[i] == trit1) {
      result += sign * 1 * pow(3, i-1);
    }
  }

  return result;
}

int singleNumber(vector<int> nums) {
  trit t[ntrits] = { trit0 };
  for (int num: nums) { tritxor(t, num); }
  // print(t);
  return from_trits(t);
}

int main(int argc, char* argv[]) {

  assert (singleNumber(std::vector<int> {2,2,3,2}) == 3);
  assert (singleNumber(std::vector<int> {0,1,0,1,0,1,99}) == 99);

  return 1;
}
