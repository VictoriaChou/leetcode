#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    bool compMap(map<string, int>& a, map<string, int>& b) {
        if(a.size() != b.size()) return false;
        map<string, int>::iterator iter;
        for(iter=a.begin(); iter != a.end(); iter++) {
            if(b.find(iter -> first) == b.end()) {
                return false;
            } else if(b[iter -> first] != iter -> second) {
                return false;
            } else {
                continue;
            }
        }
        return true;
    }
  vector<int> findSubstring(string s, vector<string>& words) {
    map<string, int> mymap;
      vector<int>res;
    for(int i=0; i<words.size(); i++) {
      mymap[words[i]]++;
    }
      int i=0;
      int j=i+words.size()*words[0].size();
      while(j<s.size()){
          string splice = s.substr(i, j-i);
          map<string, int> splicemap;
          for(int k=0; k<words.size(); k++) {
              string sub = splice.substr(k*words[0].size(), words[0].size());
              splicemap[sub]++;
          }
          map<string, int>::iterator iter;
          for(iter=splicemap.begin(); iter !=splicemap.end(); iter++) {
              cout << iter -> first << ":" << iter -> second;
          }
          cout << endl;
          if(compMap(mymap, splicemap)) {
              res.push_back(i);
          };
          i++;
          j++;
      }
      return res;
  }
};

int main() {
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    solution.findSubstring(s, words);
//    map<string, int> a = {
//        {"foo", 1},
//        {"bar", 1}
//    };
//    map<string, int> b = {
//        {"bar", 1},
//        {"foo", 1}
//    };
//    cout << solution.compMap(a, b);
    return 0;
}
