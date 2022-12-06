#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

void print(vector<int> v){
  for (int num:v) {cout << num  << " ";}
  cout << endl;
}

vector<int> sortArray(vector<int>& nums) {
  vector<int> result = {};
  int counter[100000 + 1] = { 0 };
  for (int num: nums) { counter[50000 + num] += 1; }
  for (int i=-50000; i<=50000; i++) {
    if (counter[50000+i]) {
      for (int j=0; j<counter[50000+i]; j++) { result.push_back(i); }
    }
  }
  return result;
}

int main(int argc, char* argv[]) {

  vector<int> nums = {5,1,1,2,0,0, 50000, -50000};
  print(sortArray(nums));
  // assert (singleNumber(std::vector<int> {2,2,3,2}) == 3);
  // assert (singleNumber(std::vector<int> {0,1,0,1,0,1,99}) == 99);

  return 1;
}
