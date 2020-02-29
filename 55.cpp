// 跳跃游戏, 递归，提交失败
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
  enum type {GOOD, BAD, UNKNOWN};
  vector<type> memo;
public:
  bool canJumpFromPosition(int position, vector<int>& nums) {
    if(position == nums.size() - 1) {
      return true;
    }
    int maxPosition = min<int>(nums[position] + position, nums.size() - 1);
    for(int i = maxPosition; i > position; i--) {
      if(canJumpFromPosition(i, nums)) {
        memo[position] = GOOD;
        return true;
      }
    }
    memo[position] = BAD;
    return false;
  }
  bool canJump(vector<int>& nums) {
    memo = {nums.size(), UNKNOWN};
    canJumpFromPosition(0, nums);
  }
};
