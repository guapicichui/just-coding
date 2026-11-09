/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30404
 *
 * [199] 二叉树的右视图
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
    vector<int> res;

    struct StackNode {
        TreeNode* node;
        int depth;
    };

  public:
    void fn1(TreeNode* root) {
        if (root == nullptr)
            return;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto& node = que.front();

                if (i == size - 1)
                    res.push_back(node->val);
                if (node->left != nullptr)
                    que.push(node->left);
                if (node->right != nullptr)
                    que.push(node->right);
                que.pop();
            }
        }
        return;
    }

    void fn2(TreeNode* root, int depth) {
        if (root == nullptr)
            return;
        if (depth == res.size())
            res.push_back(root->val);
        fn2(root->right, depth + 1);
        fn2(root->left, depth + 1);
    }

    void fn3(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<StackNode> st;
        st.push({root, 0});

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            if (depth == res.size())
                res.push_back(node->val);
            if (node->left != nullptr)
                st.push({node->left, depth + 1});
            if (node->right != nullptr)
                st.push({node->right, depth + 1});
        }
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        // return fn1(root);
        // fn2(root, 0);
        fn3(root);
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
