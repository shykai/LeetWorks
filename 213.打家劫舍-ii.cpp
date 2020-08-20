/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
    int robAll(vector<int> nums)
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
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0)
        {
            return 0;
        }
        else if (nums.size() <= 2)
        {
            return *max_element(nums.begin(), nums.end());
        }

        vector<int> nums1 = nums, nums2 = nums;
        nums1.erase(nums1.begin());
        nums2.pop_back();
        return max(robAll(nums1), robAll(nums2));
    }
};
// @lc code=end

