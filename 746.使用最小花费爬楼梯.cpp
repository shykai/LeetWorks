/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int Len = cost.size();
        for(int i = 2; i < Len; i++)
        {
            cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
        }

        return min(cost[Len-1], cost[Len-2]);
    }
};
// @lc code=end

