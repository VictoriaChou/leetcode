#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int k = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(i > k) return false;
        k = max<int>(k, i + nums[i]);
      }
      return true;
    }
};