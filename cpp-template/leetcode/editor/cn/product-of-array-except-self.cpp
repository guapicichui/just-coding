/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30404
 *
 * [238] 除了自身以外数组的乘积
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
    vector<int> fn1(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 0);
        vector<int> prefix(len, 1);
        vector<int> suffix(len, 1);

        for (int i = 1; i < len; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = len - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < len; ++i) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }

    vector<int> fn2(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 1);

        for (int i = 1; i < len; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = len - 2; i >= 0; --i) {
            suffix *= nums[i + 1];
            result[i] *= suffix;
        }
        return result;
    }

    vector<int> productExceptSelf(vector<int>& nums) { return fn2(nums); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */
