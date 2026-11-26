/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30404
 *
 * [51] N 皇后
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    vector<string> combo;
    vector<vector<string>> result;
    unordered_set<int> prev_col;
    unordered_set<int> prev_slash;
    unordered_set<int> prev_anti_diag;

  public:
    void buildComboDefault(int n) { combo.assign(n, string(n, '.')); }

    void dfs(int n, int i) {
        if (i == n) {
            result.push_back(combo);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (prev_col.find(j) != prev_col.end() ||
                prev_slash.find(i - j) != prev_slash.end() ||
                prev_anti_diag.find(i + j) != prev_anti_diag.end())
                continue;
            prev_col.insert(j);
            prev_slash.insert(i - j);
            prev_anti_diag.insert(i + j);
            combo[i][j] = 'Q';
            dfs(n, i + 1);
            prev_col.erase(j);
            prev_slash.erase(i - j);
            prev_anti_diag.erase(i + j);
            combo[i][j] = '.';
        }
    }

    vector<vector<string>> fn1(int n) {
        buildComboDefault(n);
        dfs(n, 0);
        return result;
    }

    vector<vector<string>> solveNQueens(int n) { return fn1(n); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
