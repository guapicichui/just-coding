/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30404
 *
 * [94] 二叉树的中序遍历
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
  public:
    void fn1(TreeNode* root, vector<int>& vec) {
        if (root == nullptr)
            return;
        fn1(root->left, vec);
        vec.push_back(root->val);
        fn1(root->right, vec);
    }

    void fn2();
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        fn1(root, vec);
        return vec;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
