/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30404
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        int area = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            int cur_area = min(height[i], height[j]) * (j - i);
            area = max(cur_area, area);
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return area;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
