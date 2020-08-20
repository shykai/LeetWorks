/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0)
        {
            return false;
        }

        map<int, int> cardMap;
        for(int i : hand)
        {
            cardMap[i]++;
        }

        for(map<int, int>::iterator iter = cardMap.begin(); iter != cardMap.end(); iter++)
        {
            if (iter->second < 0)
            {
                return false;
            }

            if (iter->second == 0)
            {
                continue;
            }

            for (size_t i = 1; i < W; i++)
            {
                cardMap[iter->first+i]-=iter->second;
            }
            iter->second = 0;
        }
        return true;
    }
};
// @lc code=end

