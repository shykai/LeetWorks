/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
    int RowMax, ColMax;

    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor)
    {
        if (sr >= RowMax || sr < 0)
            return;
        if (sc >= ColMax || sc < 0)
            return;
        
        if (image[sr][sc] != oldColor)
            return;
        
        image[sr][sc] = newColor;

        dfs(image, sr+1, sc, oldColor, newColor);
        dfs(image, sr-1, sc, oldColor, newColor);
        dfs(image, sr, sc+1, oldColor, newColor);
        dfs(image, sr, sc-1, oldColor, newColor);

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        RowMax = image.size();
        if (RowMax <= 0 || sr >= RowMax || sr < 0)
            return image;
        
        ColMax = image[0].size();
        if (ColMax <= 0 || sc >= ColMax || sc < 0)
            return image;
        
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
        {
            dfs(image, sr, sc, oldColor, newColor);
        }

        return image;
    }
};
// @lc code=end

