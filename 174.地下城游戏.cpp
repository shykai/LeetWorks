/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
    struct Node
    {
        int minHealthRequired;
        int nowHealth;
    };
    Node calcNode(Node& node, int nowPoint)
    {
        Node result;

        if (node.nowHealth + nowPoint > 0)
        {
            result.minHealthRequired = node.minHealthRequired;
            result.nowHealth = node.nowHealth + nowPoint;
        }
        else
        {
            result.minHealthRequired = node.minHealthRequired - (node.nowHealth + nowPoint) + 1;
            result.nowHealth = 1;
        }        

        return result;
    }

    Node comNode(Node node1, Node node2)
    {
        Node result;
        if (node1.minHealthRequired < node2.minHealthRequired)
        {
            return node1;
        }
        else if (node1.minHealthRequired == node2.minHealthRequired && node1.nowHealth >= node2.nowHealth)
        {
            return node1;
        }
        return node2;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int rowMax = dungeon.size();
        int colMax = dungeon[0].size();
        vector<Node> checkMap(colMax);

        for(int row = 0; row < rowMax; row++)
        {
            for(int col = 0; col < colMax; col++)
            {
                Node doNoe;
                if (row == 0 && col == 0)
                {
                    if (dungeon[row][col] >= 0)
                    {
                        doNoe.minHealthRequired = 1;
                    }
                    else
                    {
                        doNoe.minHealthRequired = 1 - dungeon[row][col];
                    }
                    
                    doNoe.nowHealth = doNoe.minHealthRequired+dungeon[row][col];
                }
                else if (row  == 0)
                {
                    doNoe = calcNode(checkMap[col-1], dungeon[row][col]);
                }
                else if (col == 0)
                {
                    doNoe = calcNode(checkMap[col], dungeon[row][col]);
                }
                else
                {
                    doNoe = comNode(calcNode(checkMap[col-1], dungeon[row][col]), calcNode(checkMap[col], dungeon[row][col]));
                }
                checkMap[col] = doNoe;
            }
        }
        
        return checkMap[colMax-1].minHealthRequired;
    }
};
// @lc code=end

