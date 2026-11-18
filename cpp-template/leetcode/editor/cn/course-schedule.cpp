/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30404
 *
 * [207] 课程表
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    vector<vector<int>> grid;
    vector<int> state;

  public:
    void build_grid(int node_num, const vector<vector<int>>& edges) {
        state.resize(node_num);
        for (auto& item : state)
            item = 0;

        grid.resize(node_num);
        for (auto& item : grid) {
            item.resize(node_num);
        }

        for (auto edge : edges) {
            grid[edge[0]][edge[1]] = 1;
        }
    }

    bool dfs(int node) {
        if (state[node] == 1)
            return false;
        if (state[node] == 2)
            return true;

        state[node] = 1;

        for (int i = 0; i < grid[node].size(); ++i) {
            if (grid[node][i] == 1)
                if (dfs(i) == false)
                    return false;
        }
        state[node] = 2;
        return true;
    }

    bool fn1(int numCourses, vector<vector<int>>& prerequisites) {
        build_grid(numCourses, prerequisites);
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i) == false)
                return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return fn1(numCourses, prerequisites);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */
