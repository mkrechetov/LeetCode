#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v) {
  cout << "[";
  for (int num: v) {cout << num << ", ";}
  cout << "]" << endl;
}

int maxSubArray(vector<int>& nums) {
  int cur = nums[0];
  int max = nums[0];

  for (int i=1; i<nums.size(); i++) {
     if (cur < 0) {cur = 0;}
     cur += nums[i];
     if (cur > max) {max = cur;}
  }

  return max;
}


int main() {
  vector<int> nums{-2, -1};
  cout << maxSubArray(nums) << endl;


  nums = vector<int>{-2, 1};
  cout << maxSubArray(nums) << endl;

  return 1;
}
