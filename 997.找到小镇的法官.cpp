/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> checkMap(N+1, 0);
        for(auto i : trust)
        {
            checkMap[i.front()]--;
            checkMap[i.back()]++;
        }

        for(int i = 1; i <= N; i++)
        {
            if (checkMap[i] == (N-1))
            {
                return i;
            }
        }
        
        return -1;
    }
};
// @lc code=end

