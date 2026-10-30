/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30404
 *
 * [145] 二叉树的后序遍历
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
    vector<int> result;

  public:
    vector<int> fn1(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* current = root;
        vector<int> result;
        TreeNode* lastVisited = nullptr;
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            TreeNode* node = st.top();

            if (node->right != nullptr && node->right != lastVisited) {
                current = node->right;
            } else {
                result.push_back(node->val);
                st.pop();
                lastVisited = node;
            }
        }
        return result;
    }

    void fn2(TreeNode* root) {
        if (root == nullptr)
            return;
        fn2(root->left);
        fn2(root->right);
        result.push_back(root->val);
        return;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        fn2(root);
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
