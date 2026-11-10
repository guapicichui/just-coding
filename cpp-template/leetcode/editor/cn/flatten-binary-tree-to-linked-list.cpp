/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30404
 *
 * [114] 二叉树展开为链表
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <queue>
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
    vector<TreeNode*> res_list;

  public:
    TreeNode* fn1(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* left_tail = fn1(root->left);
        TreeNode* right_tail = fn1(root->right);

        if (left_tail != nullptr) {
            left_tail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        if (right_tail != nullptr)
            return right_tail;
        if (left_tail != nullptr)
            return left_tail;
        return root;
    }

    void preOrder(TreeNode* root) {
        if (root == nullptr)
            return;
        res_list.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }

    void fn2(TreeNode* root) {
        if (root == nullptr)
            return;
        preOrder(root);
        for (int i = 0; i < res_list.size() - 1; ++i) {
            auto node = res_list[i];
            node->left = nullptr;
            node->right = res_list[i + 1];
        }
        auto node = res_list.back();
        node->left = node->right = nullptr;
    }

    void fn3(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left) {
                TreeNode* goal_node = cur->left;
                while (goal_node->right)
                    goal_node = goal_node->right;

                goal_node->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
        return;
    }

    void flatten(TreeNode* root) { fn2(root); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
