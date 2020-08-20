/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> goLeftList;
        stack<int> goRightList;

        for(auto i : asteroids)
        {
            if  (i < 0)
            {
                if (goRightList.empty())
                {
                    goLeftList.push_back(i);
                }
                else
                {
                    do
                    {
                        if (goRightList.top() > -i)
                        {
                            break;
                        }
                        else if (goRightList.top() == -i)
                        {
                            goRightList.pop();
                            break;
                        }
                        else
                        {
                            goRightList.pop();
                            if (goRightList.empty())
                            {
                                goLeftList.push_back(i);
                            }
                        }
                    }while (!goRightList.empty());
                }
            }
            else
            {
                goRightList.push(i);
            }
        }

        //goLeftList.insert(goLeftList.end(), goRightList.begin(), goRightList.end());
        goLeftList.resize(goLeftList.size()+goRightList.size());
        int i = goLeftList.size()-1;
        while(!goRightList.empty())
        {
            goLeftList[i] = goRightList.top();
            goRightList.pop();
            i--;
        }
        return goLeftList;
    }
};
// @lc code=end

