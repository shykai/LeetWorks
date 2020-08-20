/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
    int RowMax, ColMax;
    void buildResult(vector<vector<char>>& board, int row, int col)
    {
        if (row < 0 || row >= RowMax)
        {
            return;
        }
        if (col < 0 || col >= ColMax)
        {
            return;
        }
        if (board[row][col] == 'M')
        {
            return;
        }

        board[row][col]++;
    }
    void dfs(vector<vector<char>>& board, vector<vector<char>>& resultBoard, int row, int col)
    {
        if (row < 0 || row >= RowMax)
        {
            return;
        }
        if (col < 0 || col >= ColMax)
        {
            return;
        }

        if (board[row][col] == 'M')
        {
            board[row][col] = 'X';
        }

        if (board[row][col] == 'E')
        {
            if (resultBoard[row][col] == '0')
            {
                board[row][col] = 'B';
                dfs(board, resultBoard, row, col+1);
                dfs(board, resultBoard, row, col-1);
                dfs(board, resultBoard, row+1, col);
                dfs(board, resultBoard, row-1, col);
                dfs(board, resultBoard, row+1, col+1);
                dfs(board, resultBoard, row+1, col-1);
                dfs(board, resultBoard, row-1, col+1);
                dfs(board, resultBoard, row-1, col-1);
            }
            else if (resultBoard[row][col] > '0' && resultBoard[row][col] <= '9')
            {
                board[row][col] = resultBoard[row][col];
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        RowMax = board.size();
        ColMax = board[0].size();

        vector<vector<char>> resultBoard(RowMax,vector<char>(ColMax, '0'));

        for (int i = 0; i < RowMax; i++)
        {
            for (int j = 0; j < ColMax; j++)
            {
                if (board[i][j] == 'M')
                {
                    resultBoard[i][j] = 'M';
                    buildResult(resultBoard, i, j+1);
                    buildResult(resultBoard, i, j-1);
                    buildResult(resultBoard, i+1, j);
                    buildResult(resultBoard, i-1, j);
                    buildResult(resultBoard, i+1, j+1);
                    buildResult(resultBoard, i+1, j-1);
                    buildResult(resultBoard, i-1, j+1);
                    buildResult(resultBoard, i-1, j-1);
                }
            }
        }

        dfs(board, resultBoard, click[0], click[1]);
        return board;
    }
};
// @lc code=end

