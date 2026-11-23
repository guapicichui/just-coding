/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30404
 *
 * [39] 组合总和
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
    vector<vector<int>> result;
    vector<int> path;

  public:
    void dfs(const vector<int>& candidates, int index, int remain) {
        if (remain == 0) {
            result.push_back(path);
            return;
        }
        if (index == candidates.size())
            return;

        for (int i = index; i < candidates.size(); ++i) {
            if (remain >= candidates[i]) {
                path.push_back(candidates[i]);
                dfs(candidates, i, remain - candidates[i]);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> fn1(const vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return fn1(candidates, target);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
