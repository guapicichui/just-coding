/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30404
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> result;
        result.push_back(intervals.front());

        for (int i = 1; i < intervals.size(); ++i) {
            auto& first_range = result.back();
            const auto& second_range = intervals[i];
            if (first_range[1] >= second_range[0]) {
                first_range[1] = max(first_range[1], second_range[1]);
            } else {
                result.push_back(second_range);
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
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */
