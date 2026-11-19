/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30404
 *
 * [46] 全排列
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [1, 2, 3]
// [[1,2,3],[1,3,2], [3,1,2],[2,1,3], [2,3,1],[3,2,1]]

// @lc code=start
class Solution {
  private:
    vector<vector<int>> result;

  public:
    void backTrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backTrack(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> fn1(vector<int>& nums) {
        backTrack(nums, 0);
        return result;
    }

    vector<vector<int>> permute(vector<int>& nums) { return fn1(nums); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> nums{5, 4, 6, 2};
    auto result = solution.permute(nums);
    for (auto& item : result) {
        for (auto& num : item)
            std::cout << " " << num;
        std::cout << std::endl;
    }
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
