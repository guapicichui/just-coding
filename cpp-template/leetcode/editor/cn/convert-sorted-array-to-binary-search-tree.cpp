/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30404
 *
 * [108] 将有序数组转换为二叉搜索树
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
  private:
    struct StackNode {
        int left;
        int right;
        TreeNode*& child;
    };

  public:
    TreeNode* fn1(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int index = (left + right) / 2;
        TreeNode* node = new TreeNode{nums[index]};
        node->left = fn1(nums, left, index - 1);
        node->right = fn1(nums, index + 1, right);
        return node;
    }

    TreeNode* fn2(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        stack<StackNode> st;
        int left = 0, right = nums.size() - 1;
        int index = left + (right - left) / 2;
        TreeNode* root = new TreeNode{nums[index]};
        st.push(StackNode{index + 1, right, root->right});
        st.push(StackNode{left, index - 1, root->left});

        while (!st.empty()) {
            auto stack_node = st.top();
            st.pop();
            if (stack_node.left > stack_node.right)
                continue;

            index = stack_node.left + (stack_node.right - stack_node.left) / 2;
            TreeNode* node = new TreeNode{nums[index]};
            stack_node.child = node;
            st.push(StackNode{index + 1, stack_node.right, node->right});
            st.push(StackNode{stack_node.left, index - 1, node->left});
        }

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // return fn1(nums, 0, nums.size() - 1);
        return fn2(nums);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */
