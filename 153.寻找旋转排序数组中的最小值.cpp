/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int pre = nums[0];
        for(int i : nums)
        {
            if(pre <= i)
            {
                pre = i;
            }
            else
            {
                return i;
            }            
        }
    }
};
// @lc code=end

