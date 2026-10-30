/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30404
 *
 * [543] 二叉树的直径
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
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
    int diameter{};

  public:
    int fn1Dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = fn1Dfs(root->left);
        int right = fn1Dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

    int fn1(TreeNode* root) {
        fn1Dfs(root);
        return diameter;
    }

    int fn2(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;
        unordered_map<TreeNode*, int> tree_depth;
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            TreeNode* node = st.top();

            if (node->right != nullptr && node->right != lastVisited) {
                current = node->right;
            } else {
                int left = node->left == nullptr ? 0 : tree_depth[node->left];
                int right = node->right == nullptr ? 0 : tree_depth[node->right];
                diameter = max(diameter, left + right);
                tree_depth[node] = max(left, right) + 1;
                // 子节点的高度已被使用，不再需要保存
                if (node->left != nullptr)
                    tree_depth.erase(node->left);

                if (node->right != nullptr)
                    tree_depth.erase(node->right);
                st.pop();
                lastVisited = node;
            }
        }
        return diameter;
    }

    int diameterOfBinaryTree(TreeNode* root) { return fn2(root); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
