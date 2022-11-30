#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_map>

bool containsDuplicate(std::vector<int> nums) {
  std::unordered_map<int, int> observed;
  for (int num: nums) {
    observed[num] += 1;
    if (observed[num] == 2) {
      return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {

  assert (containsDuplicate(std::vector<int> {1,2,3,1}) == true);
  assert (containsDuplicate(std::vector<int> {1,2,3,4}) == false);
  assert (containsDuplicate(std::vector<int> {1,1,1,3,3,4,3,2,4,2}) == true);
  assert (containsDuplicate(std::vector<int> {1,1,1}) == true);
  assert (containsDuplicate(std::vector<int> {1}) == false);
  assert (containsDuplicate(std::vector<int> {2}) == false);
  assert (containsDuplicate(std::vector<int> {-2, 2}) == false);

  return 1;
}
