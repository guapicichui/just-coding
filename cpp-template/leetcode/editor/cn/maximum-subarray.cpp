/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30404
 *
 * [53] 最大子数组和
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// sum[i, j] = prefix[j + 1] - prefix[i]
// For fixed j:
// max sum[i, j] = prefix[j + 1] - min(prefix[0..j])
// @lc code=start
class Solution {
  public:
    int fn1(const vector<int>& nums) {
        int result = INT32_MIN, presum = 0, min_presum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            result = max(result, presum - min_presum);
            min_presum = min(min_presum, presum);
        }
        return result;
    }

    int fn2(const vector<int>& nums) {
        int result = INT32_MIN;
        vector<int> presum(nums.size() + 1, 0);
        for (int i = 1; i < presum.size(); ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        int min_presum = 0;
        for (int i = 0; i < presum.size() - 1; ++i) {
            min_presum = min(min_presum, presum[i]);
            result = max(presum[i + 1] - min_presum, result);
        }
        return result;
    }

    int fn3(const vector<int>& nums) {
        auto f = [&](auto&& self, int i) -> int {
            if (i == 0) {
                return nums[0];
            }

            return max(nums[i], self(self, i - 1) + nums[i]);
        };

        return f(f, nums.size() - 1);
    }

    int maxSubArray(vector<int>& nums) { return fn1(nums); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
