/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30404
 *
 * [101] 对称二叉树
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <queue>
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
    bool fn1(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> que;
        que.push(root);
        vector<TreeNode*> level_val;

        while (!que.empty()) {
            auto size = que.size();
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();
                level_val.push_back(node);
                if (node != nullptr) {
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            for (int i = 0, j = level_val.size() - 1; i < j; ++i, --j) {
                if (level_val[i] == nullptr && level_val[j] == nullptr)
                    continue;
                if (level_val[i] == nullptr || level_val[j] == nullptr)
                    return false;
                if (level_val[i]->val != level_val[j]->val)
                    return false;
            }
            level_val.clear();
        }
        return true;
    }

    bool fn2(TreeNode* root) {
        if (root == nullptr)
            return true;

        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({root->left, root->right});

        while (!que.empty()) {
            auto [a, b] = que.front();
            que.pop();

            if (a == nullptr && b == nullptr)
                continue;

            if (a == nullptr || b == nullptr)
                return false;

            if (a->val != b->val)
                return false;

            que.push({a->left, b->right});
            que.push({a->right, b->left});
        }

        return true;
    }

    bool isMirror(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;

        return a->val == b->val && isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }

    bool fn3(TreeNode* root) {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }

    bool isSymmetric(TreeNode* root) { return fn3(root); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
