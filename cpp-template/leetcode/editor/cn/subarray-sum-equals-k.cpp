/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30404
 *
 * [560] 和为 K 的子数组
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// k = sum[i, j] = presum[j + 1] - presum[i];
// @lc code=start
class Solution {
  public:
    int fn1(const vector<int>& nums, int k) {
        vector<int> presum(nums.size() + 1, 0);
        int result = 0;
        for (int i = 1; i < presum.size(); ++i) {
            presum[i] = nums[i - 1] + presum[i - 1];
        }

        for (int i = 0; i < presum.size(); ++i) {
            int require = k + presum[i];
            for (int j = i + 1; j < presum.size(); ++j) {
                if (presum[j] == require)
                    ++result;
            }
        }
        return result;
    }

    int fn2(const vector<int>& nums, int k) {
        unordered_map<long long, int> presum_count;
        int result = 0;

        long long presum = 0;
        presum_count[presum] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            if (presum_count.find(presum - k) != presum_count.end()) {
                result += presum_count[presum - k];
            }
            ++presum_count[presum];
        }
        return result;
    }

    int subarraySum(vector<int>& nums, int k) { return fn2(nums, k); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    // vector<int> arr = {1, 1, 1};
    // solution.subarraySum(arr, 2);
    //
    // std::cout << "hello" << std::endl;
    // return 0;
}

/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */
