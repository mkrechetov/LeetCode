#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

//function to print the queue
void printQueue(queue<int> q)
{
	//printing content of queue
	while (!q.empty()){
		cout<<q.front()<<", ";
		q.pop();
	}
	cout<<endl;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> counter;

  // prepare initial window
  int l(0), r(0);
  while ((r-l<=k)&&(r<nums.size())) {
    counter[nums[r]]+=1;
    if (counter[nums[r]] >= 2) {return true;}
    r++;
  }
  r--;

  while(r+1<nums.size()) {
    cout << "[" << l << "," << r << "]" << endl;
    counter[nums[l]]--;
    l++; r++;
    counter[nums[r]]++;
    if (counter[nums[r]] >= 2) {return true;}
  }

  return false;

}

int main() {

  // vector<int> case1{1,2,3,1};
  // bool res = containsNearbyDuplicate(case1, 3);
  // cout << res << endl << endl;

  vector<int> case2{1,0,1,1};
  bool res = containsNearbyDuplicate(case2, 1);
  cout << res << endl;

  return 1;
}
