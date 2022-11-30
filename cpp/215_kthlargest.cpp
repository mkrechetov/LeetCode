#include <iostream>
#include <vector>
#include <assert.h>

int findKthLargest(std::vector<int> nums, int k) {
  int present[20001] = { 0 };
  for (int num: nums) { present[10000 + num] += 1; }
  int largest_counter = 0;
  int current_position = 20001;
  while (largest_counter < k) {
    current_position -= 1;
    largest_counter += present[current_position];
  }
  std::cout << current_position << std::endl;
  return current_position - 10000;
}

int main(int argc, char* argv[]) {

  assert (findKthLargest(std::vector<int> {3,2,1,5,6,4}, 5) == 2);
  assert (findKthLargest(std::vector<int> {3,2,3,1,2,4,5,5,6}, 4) == 4);

  assert (findKthLargest(std::vector<int> {10,20,30}, 1) == 30);
  assert (findKthLargest(std::vector<int> {10,20,30}, 2) == 20);
  assert (findKthLargest(std::vector<int> {10,20,30}, 3) == 10);
  assert (findKthLargest(std::vector<int> {5, 4, 3, 2, 1}, 3) == 3);

  return 1;
}
