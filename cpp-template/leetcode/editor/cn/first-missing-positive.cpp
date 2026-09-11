/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30404
 *
 * [41] 缺失的第一个正数
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
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >= 1 && nums[i] <= nums.size() &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */
