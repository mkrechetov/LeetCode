
#include <iostream>
#include <vector>
#include <list>
#include <assert.h>
#include <math.h>

using namespace std;

const int trits = 30;

list<int> ternary(int num) {
  list<int> t;
  if (num < 0) { t.push_back(1);} else { t.push_back(2); }
  for (int i=1; i<trits; i++) { t.push_back(abs(num % 3)); num /= 3; }
  return t;
}

void print(list<int> a) {
  for (auto const& trit : a) { cout << trit; }
  cout << endl;
}

list<int> terxor(list<int> a, list<int> b) {
  list<int> t;
  list<int>::iterator it_a = a.begin();
  list<int>::iterator it_b = b.begin();

  for (int i=0; i<trits; i++) {
    t.push_back(((*it_a) + (*it_b)) % 3);
    ++it_a;
    ++it_b;
  }
  return t;
}

int from_ternary(list<int> t) {
  int result = 0;
  int sign = 1;
  list<int>::iterator it = t.begin(); ++it;

  if (t.front() == 1) { sign = -1; }
  for (int i=1; i<trits; i++) {
      result += sign * (*it) * pow(3, i-1);
      ++it;
  }

  return result;
}

int singleNumber(vector<int> nums) {
  list<int> t;
  for (int i=0; i<trits; i++) { t.push_back(0); }
  for (int num: nums) { t = terxor(t, ternary(num)); }
  print(t);
  return from_ternary(t);
}

int main(int argc, char* argv[]) {

  assert (singleNumber(std::vector<int> {2,2,3,2}) == 3);
  assert (singleNumber(std::vector<int> {0,1,0,1,0,1,99}) == 99);

  return 1;
}
