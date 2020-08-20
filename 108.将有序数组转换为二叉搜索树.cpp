/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* toBST(vector<int>& nums, int begin, int end)
    {
        if (begin == end)
        {
            return NULL;
        }
        
        int midSize = (end - begin) / 2 + begin;
        TreeNode* root = new TreeNode(nums[midSize]);
    
        root->left = toBST(nums, begin, midSize);
        root->right = toBST(nums, midSize+1, end);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen <= 0)
        {
            return NULL;
        }

        return toBST(nums, 0, numsLen);
    }
};
// @lc code=end

