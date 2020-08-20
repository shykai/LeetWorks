/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
class Solution {

    map<int, Node*> cloneMap;
    void dfsAndInit(Node* node)
    {
        if (node)
        {
            map<int, Node*>::iterator iter = cloneMap.find(node->val);
            if (iter == cloneMap.end())
            {
                cloneMap[node->val] = new Node(node->val);
                for (Node* i : node->neighbors)
                {
                    dfsAndInit(i);
                }                
            }
        }        
    }
    void dfsAndGetNeighbors(Node* node)
    {
        if (node && cloneMap[node->val]->neighbors.size() == 0)
        {
            for (Node* i : node->neighbors)
            {
                cloneMap[node->val]->neighbors.push_back(cloneMap[i->val]);
                dfsAndGetNeighbors(i);
            }
        } 
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
        {
            return NULL;
        }

        dfsAndInit(node);
        dfsAndGetNeighbors(node);

        return cloneMap[node->val];
    }
};
// @lc code=end

