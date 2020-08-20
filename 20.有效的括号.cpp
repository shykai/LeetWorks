/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> unFinishedList;
        bool result = true;
        for(char c : s)
        {
            switch(c)
            {
                case '(':
                case '{':
                case '[':
                    unFinishedList.push(c);
                    break;
                case ')':
                    {
                        if(unFinishedList.top()!= '(')
                        {
                            result = false;
                            break;
                        }
                        else
                            unFinishedList.pop();
                    }break;
                case ']':
                    {
                        if(unFinishedList.top()!= '[')
                        {
                            result = false;
                            break;
                        }
                        else
                            unFinishedList.pop();
                    }break;
                case '}':
                    {
                        if(unFinishedList.top()!= '{')
                        {
                            result = false;
                            break;
                        }
                        else
                            unFinishedList.pop();
                    }break; 
            }
        }
        if(result && unFinishedList.size() > 0)
            result = false;
        return result;
    }
};
// @lc code=end

