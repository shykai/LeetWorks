/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
    struct Node
    {
        Node(char inputChar)
        {
            chr = inputChar;
            count = 0;
        };
        char chr;
        int count;
    };
    
    void calcName(vector<Node> &doMap, string& doName)
    {
        char preChr = 0;
        for (char inputChr:doName)
        {
            if (preChr == 0 || preChr != inputChr)
            {
                preChr = inputChr;
                doMap.push_back(Node(inputChr));
            }
            else
            {
                doMap.back().count++;
            }
        }
    }

public:
    bool isLongPressedName(string name, string typed) {
        vector<Node> nameMap;
        calcName(nameMap, name);

        vector<Node> typedMap;
        calcName(typedMap, typed);

        if (nameMap.size() != typedMap.size())
        {
            return false;
        }
        
        for (int i = 0; i < nameMap.size(); i++)
        {
            if (nameMap[i].chr != typedMap[i].chr || nameMap[i].count > typedMap[i].count)
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

