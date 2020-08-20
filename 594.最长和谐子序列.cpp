/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return 0;
        }
        
        map<int, int> sumMap;
        for(int i : nums)
        {
            sumMap[i] += 1;
        }

        int result = 0;

        map<int, int>::iterator iter = sumMap.begin();
        map<int, int>::iterator pIter = iter;
        for(iter++; iter != sumMap.end(); iter++,pIter++)
        {
            if (pIter->first + 1 == iter->first)
            {
                result = max(result, pIter->second+iter->second);
            }
        }
        return result;
    }
};
// @lc code=end

