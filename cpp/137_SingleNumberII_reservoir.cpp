#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>
#include <unordered_map>

using namespace std;

const int k = 100;

int singleNumber(std::vector<int>& nums) {
  unordered_map<int, int> reservoir;

  int num;
  while (true) {
    if (nums.size() == 0) { break; }
    else {
      num = nums.back();
      nums.pop_back();

      if (reservoir.find(num) == reservoir.end()) { reservoir[num] = 1; }
      else if (reservoir[num] == 1) { reservoir[num]++; }
      else { reservoir.erase(num); }

      if (reservoir.size() == k) {
        auto random_it = std::next(std::begin(reservoir), rand()%(k));
        nums.insert(nums.begin(), random_it->first);
        if (random_it->second == 2) { nums.insert(nums.begin(), random_it->first); }
        reservoir.erase(random_it);
      }
    }
  }

  return reservoir.begin()->first;
}

int main(int argc, char* argv[]) {

  std::vector<int> a = {2,2,3,2};
  std::vector<int> b = {0,1,0,1,0,1,99};
  // cout << singleNumber(a);
  assert (singleNumber(a) == 3);
  assert (singleNumber(b) == 99);

  return 1;
}
