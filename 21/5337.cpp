#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, map<int, int>> m = {
            {'a', {0, 0}},
            {'e', {0, 0}},
            {'i', {0, 0}},
            {'o', {0, 0}},
            {'u', {0, 0}},
        };
        for(int i=0; i<s.size();i++) {
            if(m.find(s[i])!=m.end()) {
                m[s[i]][1] ++;
                if(m[s[i]][1] % 2 != 0) {
                    m[s[i]][0] = i;
                }
            }
        }
        map<char, map<int, int>>::iterator iter;
        vector<int> v;
//        for(iter = m.begin(); iter != m.end(); iter++) {
//            cout << (iter -> second)[0];
//            v.push_back((iter -> second)[0]);
//        }
        sort(v.begin(), v.end());
        int i=0, j=v[0], res=v[0];
        while(j<s.size()) {
            i=v[0] + 1;
            j = v[1];
            res = max(res, j-i+1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "eleetminicoworoep";
    sol.findTheLongestSubstring(s);
    return 0;
}
