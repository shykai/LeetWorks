/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        
        map<int, int> tmpMap;
        int idx = 0;
        for(int i : numbers)
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

