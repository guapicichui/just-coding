/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30404
 *
 * [236] 二叉树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  private:
    vector<TreeNode*> p_path;
    vector<TreeNode*> q_path;

  public:
    TreeNode* fn1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        stack<TreeNode*> st;
        TreeNode* cur_node = root;
        vector<TreeNode*> path;
        TreeNode* common_node = root;
        TreeNode* last_node = nullptr;

        while (cur_node || !st.empty()) {
            while (cur_node) {
                st.push(cur_node);
                path.push_back(cur_node);
                cur_node = cur_node->left;
            }

            auto node = st.top();
            if (node->right && node->right != last_node)
                cur_node = node->right;
            else {
                if (node == p) {
                    p_path = path;
                }
                if (node == q) {
                    q_path = path;
                }
                if (p_path.size() != 0 && q_path.size() != 0)
                    break;
                st.pop();
                path.pop_back();
                last_node = node;
            }
        }
        // find common node from p_path and q_path
        for (size_t i = 0; i < min(p_path.size(), q_path.size()); ++i) {
            if (p_path[i] != q_path[i])
                break;

            common_node = p_path[i];
        }

        return common_node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fn1(root, p, q);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */
