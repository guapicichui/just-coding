/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30404
 *
 * [22] 括号生成
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    vector<char> brackets{'(', ')'};
    vector<string> result;
    stack<char> st;
    string path;

  public:
    void dfs(int index) {
        if (index == 0) {
            if (st.empty())
                result.push_back(path);
            return;
        }

        for (auto ch : brackets) {
            path.push_back(ch);
            char top_char = 'a';
            if (!st.empty() && st.top() != ch && ch == ')') {
                top_char = st.top();
                st.pop();
            } else
                st.push(ch);
            dfs(index - 1);
            if (top_char != 'a') {
                st.push(top_char);
            } else
                st.pop();
            path.pop_back();
        }
    }

    vector<string> fn1(int n) {
        dfs(2 * n);
        return result;
    }

    vector<string> generateParenthesis(int n) { return fn1(n); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
