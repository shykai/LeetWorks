/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int> > result;
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> stack;
        dfs(root, 0, sum, stack);

        return result;
    }

    void dfs(TreeNode* root, int nowSum, int sum, vector<int> stack)
    {
        if (root == NULL)
        {

            return;
        }

        nowSum += root->val;
        stack.push_back(root->val);

        dfs(root->left, nowSum, sum, stack);
        dfs(root->right, nowSum, sum, stack);
        if (root->left == NULL && root->right == NULL)
        {
            if (nowSum == sum)
            {
                result.push_back(stack);
            }
        }        
    }
};
// @lc code=end

