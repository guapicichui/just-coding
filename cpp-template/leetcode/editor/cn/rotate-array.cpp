/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30404
 *
 * [189] 轮转数组
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    void fn1(vector<int>& nums, int k) {
        k %= nums.size();
        for (int i = 0; i < k; ++i) {
            int last_nums = nums[0], len = nums.size();
            for (int j = 0; j < len; ++j) {
                int next_index = (j + 1) % len;
                int next_nums = nums[next_index];
                nums[next_index] = last_nums;
                last_nums = next_nums;
            }
        }
        return;
    }

    void fn2(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;

        vector<int> temp_nums(len, 0);
        for (int i = 0; i < len; ++i) {
            int next_index = (i + k) % len;
            temp_nums[next_index] = nums[i];
        }
        for (int i = 0; i < len; ++i) {
            nums[i] = temp_nums[i];
        }
        return;
    }

    void fn3(vector<int>& nums, int k) {
        if (nums.empty())
            return;

        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void rotate(vector<int>& nums, int k) { return fn3(nums, k); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
