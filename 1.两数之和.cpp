/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        map<int, int> tmpMap;
        int idx = -1;
        for(int i : nums)
        {
            idx++;
            int j = target - i;
            map<int, int>::iterator iter = tmpMap.find(j);
            if (iter != tmpMap.end())
            {
                result.push_back(iter->second);
                result.push_back(idx);
                return result;
            }
            else
            {
                tmpMap[i] = idx;
            }
        }
        return result;
    }
};
// @lc code=end

