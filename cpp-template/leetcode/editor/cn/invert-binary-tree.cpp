/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30404
 *
 * [226] 翻转二叉树
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <stack>
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
    void fn1(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->left != nullptr || root->right != nullptr) {
            swap(root->left, root->right);
        }
        fn1(root->left);
        fn1(root->right);
    }

    void fn2(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node->left != nullptr || node->right != nullptr) {
                swap(node->left, node->right);
            }
            if (node->right != nullptr)
                st.push(node->right);
            if (node->left != nullptr)
                st.push(node->left);
        }
        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        fn2(root);
        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
