/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30404
 *
 * [78] 子集
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
    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        dfs(nums, index + 1);
        path.pop_back();

        dfs(nums, index + 1);
    }

    vector<vector<int>> fn1(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) { return fn1(nums); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
