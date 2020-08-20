/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int Len = A.size();
        if (Len <= 0)
        {
            return 0;
        }
        
        vector<int> checkMap;
        checkMap.push_back(0);
        int oneCount = 0;
        for (int i = 0; i < Len; i++)
        {
            if (A[i] == 0)
            {
                checkMap[oneCount]++;
            }
            else
            {
                oneCount++;
                checkMap.push_back(0);
            }
        }
        
        if (S > oneCount)
        {
            return 0;
        }
        
        int result = 0;
        int begin = 0;
        int end = S;
        for (; end < oneCount+1; begin++,end++)
        {
            if (begin == end)
            {
                result += checkMap[begin]*(checkMap[begin]+1)/2;
            }
            else
            {
                result += (checkMap[begin]+1) * (checkMap[end]+1);
            }
        }

        return result;
    }
};
// @lc code=end

