/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30404
 *
 * [437] 路径总和 III
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  private:
    unordered_map<long long, int> prefix_count;
    int result;
    int target;

  public:
    void fn1(TreeNode* root, long long prefix) {
        if (root == nullptr)
            return;
        prefix += root->val;
        if (auto it = prefix_count.find(prefix - target); it != prefix_count.end()) {
            result += it->second;
        }

        ++prefix_count[prefix];
        fn1(root->left, prefix);
        fn1(root->right, prefix);
        if (--prefix_count[prefix] == 0)
            prefix_count.erase(prefix);
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        result = 0;
        prefix_count[0] = 1;
        fn1(root, 0);
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
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
