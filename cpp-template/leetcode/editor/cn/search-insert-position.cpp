/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30404
 *
 * [35] 搜索插入位置
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
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        if (nums[i] > target)
            return i;
        if (nums[j] < target)
            return j + 1;
        for (; i < j;) {
            auto mid = (j - i) / 2 + i;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] > target)
                j = mid;
        }
        return i;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */
