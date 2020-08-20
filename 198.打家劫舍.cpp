/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (numsLen <= 0)
        {
            return 0;
        }

        int result = nums[0];
        for (size_t i = 0; i < numsLen; i++)
        {
            if (i == 2)
            {
                nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
            }
            else if (i > 2)
            {
                nums[i] = max(nums[i - 1], nums[i] + max(nums[i - 2], nums[i - 3]));
            }

            result = max(result, nums[i]);
        }
        return result;
    }
};
// @lc code=end
