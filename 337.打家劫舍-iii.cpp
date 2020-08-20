/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    struct NodeResult
    {
        NodeResult()
        {
            doNode = 0;
            notNode = 0;
        };
        int doNode;
        int notNode;
    };
    NodeResult checkNode(TreeNode* root)
    {
        NodeResult result;

        if (root)
        {
            NodeResult leftResult = checkNode(root->left);
            NodeResult rightResult = checkNode(root->right);

            result.doNode = root->val + leftResult.notNode + rightResult.notNode;
            result.notNode = max(leftResult.notNode, leftResult.doNode) + max(rightResult.notNode, rightResult.doNode);
        }
        return result;
    };
public:
    int rob(TreeNode* root) {
        NodeResult result = checkNode(root);
        return max(result.notNode, result.doNode);
    }
};
// @lc code=end

