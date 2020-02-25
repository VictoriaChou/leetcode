// 两数之和
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sumMap;
        map<int, int>::iterator iter;
        for (int j = 0; j < nums.size(); j++) {
            iter = sumMap.find(nums[j]);
            if( iter != sumMap.end() && j != (*iter).second) {
                return {(*iter).second, j};
            }
            sumMap[target - nums[j]] =  j;
        }
        return {};
    }
};