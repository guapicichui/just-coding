/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30404
 *
 * [15] 三数之和
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            long long target = -static_cast<long long>(nums[i]);
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                long long cur_sum = static_cast<long long>(nums[j]) + nums[k];
                if (cur_sum == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                } else if (cur_sum > target)
                    --k;
                else
                    ++j;
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
