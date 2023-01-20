#include <iostream>
#include <map>

using namespace std;

multimap<int, char> invert(map<char, int> & mymap){
    multimap<int, char> multiMap;
    map<char, int>::iterator it;
    for (it=mymap.begin(); it!=mymap.end(); it++) {
        multiMap.insert(make_pair(it->second, it->first));
    }

    return multiMap;
}

string frequencySort(string s) {
    map<char, int> counter;

    for (char c: s) {counter[c]--;}

    multimap<int, char> newmap = invert(counter);

    string result = "";
    for (auto it: newmap) {
        for (int i=0; i<abs(it.first); i++) {
            result += it.second;
        }
    }

    return result;
}

int main() {

  cout << frequencySort("tree") << endl;
  cout << frequencySort("Aabb") << endl;

  return 1;
}
