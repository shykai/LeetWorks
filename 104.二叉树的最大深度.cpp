/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
            
        int depth = 1;
        if (root->left)
        {
            depth = max(depth, maxDepth(root->left)+1);
        }
        if (root->right)
        {
            depth = max(depth, maxDepth(root->right)+1);
        }

        return depth;
    }

};
// @lc code=end

