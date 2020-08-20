/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> s1Count, s2Count;
        for(char i : s1)
        {
            s1Count[i]+=1;
        }
        for(char i : s2)
        {
            s2Count[i]+=1;
        }

        for(map<char, int>::iterator iter = s1Count.begin(); iter != s1Count.end(); iter++)
        {
            if(s2Count[iter->first] < iter->second)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

