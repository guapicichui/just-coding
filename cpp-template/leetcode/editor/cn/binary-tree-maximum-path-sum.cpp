/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30404
 *
 * [124] 二叉树中的最大路径和
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
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
    int global_max_sum{INT32_MIN};

  public:
    int fn1(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto left_max = max(0, fn1(root->left));
        auto right_max = max(0, fn1(root->right));
        auto root_max = max(left_max, right_max);
        global_max_sum = max(global_max_sum, root->val + left_max + right_max);

        return root_max + root->val;
    }

    int maxPathSum(TreeNode* root) {
        fn1(root);
        return global_max_sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */
