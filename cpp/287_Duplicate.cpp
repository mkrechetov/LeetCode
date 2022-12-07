#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

void print_vec(vector<int> v){for(int num:v){cout<<num<<" ";} cout<<endl;}
void print_arr(int*b){for(int i=0;i<31;i++){cout<<b[i]<<" ";} cout<<endl;}

int findDuplicate(vector<int>& nums) {
  int expected_occ[31] = { 0 };
  int observed_occ[31] = { 0 };
  for (int i=0; i<nums.size(); i++) {
      for (int j=0,mask=1; j<31; j++, mask <<= 1) {
          if ((i & mask) == mask) {expected_occ[j]++;}
          if ((nums[i] & mask) == mask) {observed_occ[j]++;}
      }
  }
  print_arr(expected_occ);
  print_arr(observed_occ);
  cout << endl;

  int res = 0;
  for (int j=0,mask=1; j<31; j++, mask <<= 1) {
      if (expected_occ[j] < observed_occ[j]) { res += mask;}
  }
  return res;
}

int main(int argc, char* argv[]) {

  vector<int> v1 = {1,3,4,2,2};
  findDuplicate(v1);

  vector<int> v2 = {3,1,3,4,2};
  findDuplicate(v2);

  vector<int> v3 = {2,2,2,2,2};
  findDuplicate(v3);


  return 1;
}
