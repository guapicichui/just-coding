/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30404
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    que.push(node->left);
                if (node->right != nullptr)
                    que.push(node->right);
            }
            result.push_back(std::move(level));
        }
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
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
