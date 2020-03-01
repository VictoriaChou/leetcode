#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string rankTeams(vector<string> &votes)
  {
    map<char, map<int, int>> res;
    for (auto s : votes)
    {
      for (int i = 0; i < s.size(); i++)
      {
        res[s[i]][i]++;
      }
    }
    sort(votes[0].begin(), votes[0].end(), [&](char a, char b) -> bool {
      for (int i = 0; i < votes[0].size(); i++)
      {
        if(res[a][i] > res[b][i]) {
          return 1;
        }
        if(res[a][i] < res[b][i]) {
          return 0;
        }
      }
      return a < b;
    });
    return votes[0];
  }
};