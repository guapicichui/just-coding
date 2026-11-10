/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30404
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <memory>
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
    unordered_map<int, int> position;
    const vector<int>* preorder_ = nullptr;
    const vector<int>* inorder_ = nullptr;

    TreeNode* build(int root_index, int in_left, int in_right) {
        if (in_left > in_right)
            return nullptr;

        int val = (*preorder_)[root_index];

        int i = position[val];

        int left_size = i - in_left;

        TreeNode* node = new TreeNode(val);

        node->left = build(root_index + 1, in_left, i - 1);

        node->right = build(root_index + 1 + left_size, i + 1, in_right);

        return node;
    }

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_ = &preorder;
        inorder_ = &inorder;
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i)
            position[inorder[i]] = i;
        return build(0, 0, static_cast<int>(inorder.size()) - 1);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
