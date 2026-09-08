/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30404
 *
 * [239] 滑动窗口最大值
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    struct IndexNum {
        int index{};
        int num{};
    };

    struct Compare {
        bool operator()(const IndexNum& a, const IndexNum& b) const {
            return a.num < b.num;
        }
    };

    vector<int> fn1(const vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }

    vector<int> fn2(const vector<int>& nums, int k) {
        if (nums.size() == 0)
            return {};

        vector<int> result;
        priority_queue<IndexNum, vector<IndexNum>, Compare> max_heap;

        int min_len = min(static_cast<int>(nums.size()), k);
        for (int i = 0; i < min_len; ++i) {
            max_heap.push({i, nums[i]});
        }
        result.push_back(max_heap.top().num);

        if (static_cast<int>(nums.size()) > k) {
            for (int i = 1; i < nums.size() - k + 1; ++i) {
                max_heap.push({i + k - 1, nums[i + k - 1]});
                while (!max_heap.empty() && max_heap.top().index < i) {
                    max_heap.pop();
                }
                result.push_back(max_heap.top().num);
            }
        }
        return result;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) { return fn1(nums, k); }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<int> vec{9, 10, 9, -7, -4, -8, 2, -6};
    solution.maxSlidingWindow(vec, 5);
    // your test code here
}

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
