#include <iostream>
#include <map>
#include <string>

using namespace std;
class Solution {
public:
    string sortString(string s) {
        sort(s.begin(),s.end());
        map<char, int> mymap;
        string res;
        for(int i=0; i<s.size(); i++) {
            mymap[s[i]] ++;
        }
        map<char, int>::iterator iter;
        int max = 0;
        for(iter =mymap.begin(); iter != mymap.end(); iter++) {
            max = max > iter -> second ? max : iter -> second;
        }
        for(int k = 1; k<=max; k++) {
            string tmp;
            for(iter =mymap.begin(); iter != mymap.end(); iter++) {
                if(iter -> second >= k) {
                    tmp += iter->first;
                }
            }
            if(k % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            res += tmp;
        }
        cout << res <<endl;
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aaaabbbbcccc";
    sol.sortString(s);
    return 0;
}
