#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


bool checkSubarraySum(vector<int>& nums, int k) {
  if (nums.size() <= 1) {return false;}
  else {
    unordered_map<int, int> prefixsum;
    int currsum = 0;
    for (int i=0; i<nums.size(); i++) {
      currsum = (currsum + nums[i]) % k;
      if ((nums[i]!=0) && (currsum==0)) {return true;}

      if (prefixsum.find(currsum) != prefixsum.end()) {
        if (i-prefixsum[currsum] >= 2) {return true;}
      } else {
        prefixsum[currsum] = i;
      }
    }
    return false;
  }
}

int main() {

  vector<int> v1{23,2,4,6,6};
  cout << checkSubarraySum(v1, 7) << endl;
  vector<int> v2{0,1,0,3,0,4,0,4};
  cout << checkSubarraySum(v2, 5) << endl;

  return 1;
}
