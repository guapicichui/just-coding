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
#include <tuple>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    vector<tuple<int, int>> combo;
    vector<vector<tuple<int, int>>> result;

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

    bool isPalindrome(const string& s, int start, int end) {
        int left = start;
        int right = end;

        while (left < right) {
            if (s[left] != s[right])
                return false;

            ++left;
            --right;
        }

        return true;
    }

  public:
    void dfs(const string& str, int start, int end) {
        if (start == str.size() && end == str.size()) {
            result.push_back(combo);
            return;
        }
        if (end == str.size())
            return;

        if (isPalindrome(str, start, end)) {
            combo.push_back({start, end});

            dfs(str, end + 1, end + 1);

            combo.pop_back();
        }

        dfs(str, start, end + 1);
    }

    vector<vector<string>> fn1(const string& str) {
        dfs(str, 0, 0);
        vector<vector<string>> result_str;
        for (const auto& item : result) {
            vector<string> combination;
            for (auto [i, j] : item) {
                combination.push_back(str.substr(i, j - i + 1));
            }
            result_str.push_back(combination);
        }
        return result_str;
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
