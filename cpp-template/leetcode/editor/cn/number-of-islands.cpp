/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30404
 *
 * [200] 岛屿数量
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    int result;

  public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        if (i != 0)
            dfs(grid, i - 1, j);
        if (i != grid.size() - 1)
            dfs(grid, i + 1, j);
        if (j != 0)
            dfs(grid, i, j - 1);
        if (j != grid[i].size() - 1)
            dfs(grid, i, j + 1);
    }

    int fn1(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    dfs(grid, i, j);
                }
            }
        return result;
    }

    int numIslands(vector<vector<char>>& grid) { return fn1(grid); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
//
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
//
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
