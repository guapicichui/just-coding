#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <stack>
using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
    vector<int> res;

    void fn1(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        fn1(root->left);
        fn1(root->right);
    }

    void fn2(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node == nullptr)
                continue;
            res.push_back(node->val);
            st.push(node->right);
            st.push(node->left);
        }
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // fn1(root);
        fn2(root);
        return res;
    }
};

// leetcode submit region end(Prohibit modification and deletion)

int main() {
    // your test code here
    Solution solution;
    TreeNode* root = TreeNode::createRoot(
        {1, 22, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9});
    vector<int> result = solution.preorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
}
