/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool result = true;
    int dfs(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);

        if (abs(leftDepth - rightDepth) > 1)
        {
            result = false;
            throw false;
        }

        return max(leftDepth, rightDepth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        try
        {
            dfs(root);
        }
        catch(bool)
        {
        }
        
        
        return result;
    }
};
// @lc code=end

