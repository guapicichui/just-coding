/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30404
 *
 * [100] 相同的树
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
    bool fn1(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        queue<TreeNode*> st_p;
        queue<TreeNode*> st_q;
        st_p.push(p);
        st_q.push(q);

        while (!st_p.empty() && !st_q.empty()) {
            auto size_p = st_p.size();
            auto size_q = st_q.size();
            if (size_p != size_q)
                return false;
            for (int i = 0; i < size_p; ++i) {
                auto node_p = st_p.front();
                auto node_q = st_q.front();
                st_p.pop();
                st_q.pop();
                if (node_p && node_q) {
                    if (node_p->val != node_q->val)
                        return false;
                    st_p.push(node_p->left);
                    st_p.push(node_p->right);
                    st_q.push(node_q->left);
                    st_q.push(node_q->right);
                }
                if (node_p == nullptr && node_q == nullptr)
                    continue;
                if (node_p == nullptr || node_q == nullptr)
                    return false;
            }
        }
        if (!st_p.empty() || !st_q.empty())
            return false;
        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) { return fn1(p, q); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */
