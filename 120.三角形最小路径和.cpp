/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.size() == 1)
        {
            return triangle.front().front();
        }

        int tmpLen = triangle.size();
        vector<int> tmp(tmpLen);
        
        tmp[triangle.size()-1] = triangle.front().front();
        for(int row = 1; row < tmpLen; row++)
        {
            for(int col = 0; col <= row; col++) //check row: triangle[row]
            {
                int doCol = tmpLen - row + col - 1;
                if (col == 0)
                {
                    tmp[doCol] = tmp[doCol+1] + triangle[row][col];
                }
                else if (col == row)
                {
                    tmp[doCol] = tmp[doCol]+ triangle[row][col];
                }
                else
                {
                    if( tmp[doCol] < tmp[doCol+1])
                    {
                        tmp[doCol] = tmp[doCol] + triangle[row][col];
                    }
                    else
                    {
                        tmp[doCol] = tmp[doCol+1] + triangle[row][col];
                    }
                }
            }
        }

        int result = tmp[0];
        for(int i = 1; i < tmpLen; i++)
        {
            if (result > tmp[i])
            {
                result = tmp[i];
            }
        }
        return result;
    }
};
// @lc code=end

