/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30404
 *
 * [283] 移动零
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
