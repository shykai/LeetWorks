/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int vecLength = A.size();
        for (int i = 1; i < vecLength; i++)
        {
            if (A[i] < A[i-1])
            {
                return i-1;
            }
        }
        return 0;
    }
};
// @lc code=end

