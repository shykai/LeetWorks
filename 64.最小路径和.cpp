/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        vector<int> tmpRow(colCount);

        for(int row = 0; row < rowCount; row++)
        {
            for(int col = 0; col < colCount; col++)
            {
                if(row == 0 && col == 0)
                {
                    tmpRow[col] = grid[row][col];
                }
                else if(row == 0)
                {
                    tmpRow[col] = grid[row][col] + tmpRow[col-1];
                }
                else if(col == 0)
                {
                    tmpRow[col] = grid[row][col] + tmpRow[col];
                }
                else
                {
                    tmpRow[col] = min(tmpRow[col], tmpRow[col-1]) + grid[row][col];
                }                
            }
        }
        
        return tmpRow[colCount-1];
    }
};
// @lc code=end

