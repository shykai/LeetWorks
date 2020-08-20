/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
    int maxPartProfit(int days, vector<int>::iterator begin)
    {
        begin++;
        if (days < 2)
        {
            return 0;
        }
        
        int minPrice = *begin;begin++;
        int result = 0;
        for (int i = 1; i < days; i++,begin++)
        {
            result = max(result, *begin-minPrice);
            minPrice = min(minPrice, *begin);
        }

        return result;
    }
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days < 2)
        {
            return 0;
        }
        
        int minPrice = prices[0];
        int resultOne = 0;
        int result = 0;
        int nowDays = days-2;
        vector<int>::iterator i = prices.begin();
        for (i++; i != prices.end(); i++,nowDays--)
        {
            resultOne = max(resultOne, *i-minPrice);
            int resultTwo = maxPartProfit(nowDays, i);
            result = max(result, resultOne + resultTwo);
            minPrice = min(minPrice, *i);
        }

        return result;
    }
};
// @lc code=end

