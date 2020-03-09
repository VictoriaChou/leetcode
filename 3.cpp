// Longest Substring Without Repeating Characters
#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int res = 0;
    map<char, int> myMap;
    for(int i = 0, j = 0; j < s.size(); j++) {
      if(myMap.find(s[j]) != myMap.end()) {
        i = max(i, myMap[s[j]]);
      }
      myMap[s[j]] = j + 1;
      res = max(res, j - i + 1);
    }
    return res;
  }
};

int main()
{
  Solution s;
  int max = s.lengthOfLongestSubstring("abcabcbb");
  cout << max;
  return max;
}
