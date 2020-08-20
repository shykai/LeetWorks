/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        map<int, int> sMap, tMap;
        for(char i : s)
        {
            sMap[i-'a'] +=1;
        }
        for(char i : t)
        {
            tMap[i-'a'] +=1;
        }
        for(map<int, int>::iterator iter = sMap.begin(); iter != sMap.end(); iter++)
        {
            if (tMap[iter->first] != iter->second)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

