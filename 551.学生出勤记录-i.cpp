/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int Acount = 0;
        int Lcount = 0;
        for (char i : s)
        {
            if (i == 'L')
            {
                Lcount ++;
            }
            else
            {
                Lcount = 0;
                if (i == 'A')
                {
                    Acount++;
                }
            }

            if (Acount > 1 || Lcount > 2)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

