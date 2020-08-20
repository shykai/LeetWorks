/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
        {
            return false;
        }

        ListNode* fastNode = head;
        ListNode* slowNode = head;
        while (fastNode && fastNode->next)
        {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;

            if (fastNode == slowNode)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

