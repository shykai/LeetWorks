/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {

int RowMax, ColMax;

void dfs(vector<vector<char>>& board, int x, int y)
{
    if (x < 0 || x >= RowMax || y < 0 || y >= ColMax || board[x][y] != 'O')
    {
        return;
    }

    board[x][y] = 'L'; //lake
    dfs(board, x-1, y);
    dfs(board, x+1, y);
    dfs(board, x, y+1);
    dfs(board, x, y-1);
}

public:
    void solve(vector<vector<char>>& board) {
        RowMax = board.size();
        if (RowMax <= 0)
        {
            return;
        }

        ColMax = board[0].size();
        if (ColMax <= 0)
        {
            return;
        }

        for (size_t x = 0; x < RowMax; x++)
        {
            dfs(board, x, 0);
            dfs(board, x, RowMax-1);
        }
        for (size_t y = 0; y < ColMax; y++)
        {
            dfs(board, 0, y);
            dfs(board, RowMax-1, y);
        }
        
        for (size_t x = 0; x < RowMax; x++)
        {
            for (size_t y = 0; y < ColMax; y++)
            {
                if (board[x][y] == 'O')
                {
                    board[x][y] = 'X';
                }
                else if (board[x][y] == 'L')
                {
                    board[x][y] = 'O';
                }
            }
        }
    }
};
// @lc code=end

