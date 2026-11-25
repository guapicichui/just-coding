/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30404
 *
 * [131] 分割回文串
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    string path;
    vector<string> combo;
    vector<vector<string>> result;

    bool isPalindrome(const string& s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            if (s[left] != s[right])
                return false;

            ++left;
            --right;
        }

        return true;
    }

  public:
    void dfs(const string& str, int index) {
        if (index == str.size()) {
            result.push_back(combo);
            return;
        }

        path.push_back(str[index++]);

        if (isPalindrome(path)) {
            combo.push_back(path);
            path.clear();
            dfs(str, index);
            auto last_str = combo.back();
            combo.pop_back();
            path = last_str;
        }

        if (index != str.size())
            dfs(str, index);

        path.pop_back();
    }

    vector<vector<string>> fn1(const string& str) {
        dfs(str, 0);
        return result;
    }

    vector<vector<string>> partition(string s) { return fn1(s); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */
