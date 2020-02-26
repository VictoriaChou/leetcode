// Longest Palindromic Substring
// 动态规划
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int len = s.size();
    string res = "";
    int tmpMaxLen = 0;
    if (len == 0)
      return res;
    if (len == 1)
      return s;
    res = s[0];
    vector<vector<bool>> dp(len, vector<bool>(len));
    for (int i = 0; i < len; i++)
    {
      for (int j = i; j >= 0; j--)
      {
        if (s[i] == s[j] && (i - j <= 2 || dp[i - 1][j + 1]))
        {
          dp[i][j] = true;
          if (i - j > tmpMaxLen)
          {
            res = s.substr(j, i - j + 1);
            tmpMaxLen = i - j;
          }
        }
      }
    }
    return res;
  }
};