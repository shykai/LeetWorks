/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
     set<int> todoList;
    map<int, int> colorMap;
    bool doColor(int point, int color, vector<vector<int>>& graph)
    {
        for(int j : graph[point])
        {
            set<int>::iterator it = todoList.find(j);
            if (it == todoList.end())
            {
                if (colorMap[j] != color)
                {
                    return false;
                }
            }
            else
            {
                colorMap[j] = color;
                todoList.erase(j);
                if (!doColor(j, 0-color, graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++)
        {
            todoList.insert(i);
            colorMap[i]= 0;
        }

        bool result = true;
        while(!todoList.empty())
        {
            set<int>::iterator it = todoList.begin();
            int i = *it;todoList.erase(it);
            colorMap[i] = 1;
            if (!doColor(i, -1, graph))
            {
                return false;
            }
        }
        
        return result;
    }
};
// @lc code=end

