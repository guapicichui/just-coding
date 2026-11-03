/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30404
 *
 * [230] 二叉搜索树中第 K 小的元素
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
  private:
    int num_k;
    int result;

  public:
    int fn1(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            auto node = st.top();
            st.pop();
            if (--k == 0)
                return node->val;
            cur = node->right;
        }
        return true;
    }

    void fn2Recursion(TreeNode* root) {
        if (root == nullptr)
            return;
        fn2Recursion(root->left);
        if (--num_k == 0)
            result = root->val;
        fn2Recursion(root->right);
    }

    int fn2(TreeNode* root, int k) {
        num_k = k;
        fn2Recursion(root);
        return result;
    }

    int kthSmallest(TreeNode* root, int k) { return fn2(root, k); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */
