/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30404
 *
 * [104] 二叉树的最大深度
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
  public:
    void fn1(TreeNode* root, int& cur, int& depth) {
        if (root == nullptr) {
            depth = max(depth, cur);
            return;
        }
        ++cur;
        fn1(root->left, cur, depth);
        fn1(root->right, cur, depth);
        --cur;
    }

    int fn2(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(fn2(root->left), fn2(root->right));
    }

    int fn3(TreeNode* root) {
        if (root == nullptr)
            return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int max_depth = 0;

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            max_depth = max(max_depth, depth);
            if (node->right != nullptr)
                st.push({node->right, depth + 1});
            if (node->left != nullptr)
                st.push({node->left, depth + 1});
        }

        return max_depth;
    }

    int fn4(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;

        while (!que.empty()) {
            auto que_size = que.size();
            for (int i = 0; i < que_size; ++i) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left != nullptr)
                    que.push(node->left);
                if (node->right != nullptr)
                    que.push(node->right);
            }

            ++depth;
        }
        return depth;
    }

    int maxDepth(TreeNode* root) {
        // int cur = 0, depth = 0;
        // fn1(root, cur, depth);
        // return depth;
        return fn4(root);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */
