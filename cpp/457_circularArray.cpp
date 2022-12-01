#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_map>

bool circularArrayLoop(std::vector<int> nums) {
  std::unordered_map<int, bool> visited;
  int n = nums.size();
  if (n == 1) {return false;}

  for (int i=0; i<n; i++) {
    int prev = -1;
    int curr = i;
    if (!visited[curr]) {
      std::cout << "Starting walk at position " << curr << std::endl;
      visited[curr] = true;
      std::unordered_map<int, bool> visited_this_walk;

      while (prev != curr) {
        if (visited_this_walk[curr]) {
          return true;
        } else {
          visited_this_walk[curr] = true;
          visited[curr] = true;
          prev = curr;
          int num = nums[curr];
          if (num < 0) {num = n+num;}
          curr = (curr + num) % n;
          std::cout << "Jumped to position " << curr << std::endl;
        }
      }
    }
  }
  return false;
}

int main(int argc, char* argv[]) {

  assert (circularArrayLoop(std::vector<int> {2,-1,1,2,2}) == true);
  assert (circularArrayLoop(std::vector<int> {-1,-2,-3,-4,-5,6}) == false);
  assert (circularArrayLoop(std::vector<int> {1,-1,5,1,4}) == true);

  assert (circularArrayLoop(std::vector<int> {1,1,1,1,1}) == true);
  assert (circularArrayLoop(std::vector<int> {1}) == false);
  assert (circularArrayLoop(std::vector<int> {2, 2}) == false);

  return 1;
}
