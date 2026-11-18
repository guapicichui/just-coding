/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30404
 *
 * [994] 腐烂的橘子
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    int result{};
    int fresh_count{};

  public:
    void bfs(vector<vector<int>>& grid, const vector<tuple<int, int>>& start) {
        if (start.empty())
            return;
        queue<tuple<int, int>> que;
        for (auto [i, j] : start)
            que.push({i, j});

        while (!que.empty()) {
            auto len = que.size();
            ++result;
            for (int i = 0; i < len; ++i) {
                auto [m, n] = que.front();
                que.pop();
                if (m != grid.size() - 1 && grid[m + 1][n] == 1) {
                    grid[m + 1][n] = 2;
                    que.push({m + 1, n});
                    --fresh_count;
                }
                if (m != 0 && grid[m - 1][n] == 1) {
                    grid[m - 1][n] = 2;
                    que.push({m - 1, n});
                    --fresh_count;
                }
                if (n != grid[m].size() - 1 && grid[m][n + 1] == 1) {
                    grid[m][n + 1] = 2;
                    que.push({m, n + 1});
                    --fresh_count;
                }
                if (n != 0 && grid[m][n - 1] == 1) {
                    grid[m][n - 1] = 2;
                    que.push({m, n - 1});
                    --fresh_count;
                }
            }
        }
        --result;
        return;
    }

    int fn1(vector<vector<int>>& grid) {
        vector<tuple<int, int>> bfs_start;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1)
                    ++fresh_count;
                if (grid[i][j] == 2)
                    bfs_start.push_back({i, j});
            }
        bfs(grid, bfs_start);
        return fresh_count == 0 ? result : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) { return fn1(grid); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
