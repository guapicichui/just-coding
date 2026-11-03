/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30404
 *
 * [98] 验证二叉搜索树
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
    bool fn1TreeMinMax(TreeNode* root, int& min_val, int& max_val) {
        min_val = max_val = root->val;

        if (root->left != nullptr) {
            int left_min, left_max;
            if (!fn1TreeMinMax(root->left, left_min, left_max))
                return false;
            if (left_max >= root->val)
                return false;
            min_val = left_min;
        }

        if (root->right != nullptr) {
            int right_min, right_max;
            if (!fn1TreeMinMax(root->right, right_min, right_max))
                return false;
            if (right_min <= root->val)
                return false;
            max_val = right_max;
        }

        return true;
    }

    bool fn1(TreeNode* root) {
        if (root == nullptr)
            return true;

        int min_val, max_val;
        return fn1TreeMinMax(root, min_val, max_val);
    }

    bool fn2(TreeNode* root) {
        if (root == nullptr)
            return true;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;

        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            auto node = st.top();
            st.pop();

            if (prev != nullptr && node->val <= prev->val)
                return false;
            prev = node;
            cur = node->right;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) { return fn2(root); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
