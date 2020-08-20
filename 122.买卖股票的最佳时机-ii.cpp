/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
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
        
        int tmpRet = 0;
        vector<int> resultList;
        for (int i = 1; i < days; i++)
        {
            if (prices[i] > prices[i-1])
            {
                tmpRet += prices[i] - prices[i-1];
            }
            else
            {
                resultList.push_back(tmpRet);
                tmpRet = 0;
            }
        }
        resultList.push_back(tmpRet);

        int result = 0;
        sort(resultList.begin(), resultList.end());
        for (int i = 0; i < resultList.size() && i < 2; i++)
        {
            result += resultList[resultList.size()-1-i];
        }

        return result;
    }
};
// @lc code=end

