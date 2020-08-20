/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days < 2)
        {
            return 0;
        }
        
        int minPrice = prices[0];
        int result = 0;
        for (int i = 1; i < days; i++)
        {
            result = max(result, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return result;
    }
};
// @lc code=end

