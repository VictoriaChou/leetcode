#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:

  // 解法1，超时
  int numTimesAllBlue(vector<int> &light)
  {
    vector<int> copy = light;
    sort(copy.begin(), copy.end());
    if (light == copy)
      return light.size();
    enum status
    {
      off,
      on,
      blue
    };
    int res = 0;
    map<int, status> m;
    for (int i = 0; i < light.size(); i++)
    {
      m[i + 1] = off;
    }
    int mx = 0;
    for (int i = 0; i < light.size(); i++)
    {
      mx = max(light[i], mx);
      m[light[i]] = on;
      bool isBule = true;
      if (m[mx - 1] == blue)
      {
        isBule = true;
      }
      else
      {
        for (int j = 0; j < mx; j++)
        {
          if (m[j + 1] == off)
          {
            isBule = false;
            break;
          }
        }
      }
      if (isBule)
      {
        res++;
        m[light[i]] = blue;
        cout << i << endl;
      }
    }
    return res;
  }

  // 解法2
  int numTimesAllBlue2(vector<int> &light)
  {
    int mx = 0, sum = 0, res = 0;
    for(int i=0; i<light.size(); i++) {
      mx = max(mx, light[i]);
      if(mx == i + 1) res++;
    }
    return res;
  }
};
int main()
{
  Solution s;
  vector<int> light = {1, 8, 3, 4, 9, 6, 7, 2, 5, 10};
  cout << s.numTimesAllBlue(light);
  return 0;
}
