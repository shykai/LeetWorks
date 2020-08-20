/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> innerMap;
        for(int i : nums1)
        {
            innerMap[i]++;
        }
        for(int i :nums2)
        {
            if(innerMap[i]>0)
            {
                innerMap[i]--;
                result.push_back(i);                
            }
        }

        return result;
    }
};
// @lc code=end

