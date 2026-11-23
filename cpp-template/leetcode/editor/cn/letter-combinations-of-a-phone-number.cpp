/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30404
 *
 * [17] 电话号码的字母组合
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
    vector<vector<char>> digit_char;
    vector<string> result;
    string path;

  public:
    void makeDigitChar() {
        digit_char = {
            {'a', 'b', 'c'},      // 2
            {'d', 'e', 'f'},      // 3
            {'g', 'h', 'i'},      // 4
            {'j', 'k', 'l'},      // 5
            {'m', 'n', 'o'},      // 6
            {'p', 'q', 'r', 's'}, // 7
            {'t', 'u', 'v'},      // 8
            {'w', 'x', 'y', 'z'}  // 9
        };
    }

    void dfs(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        for (char c : digit_char[digits[index] - '2']) {
            path.push_back(c);
            dfs(digits, index + 1);
            path.pop_back();
        }
    }

    vector<string> fn1(const string& digits) {
        if (digits.empty())
            return {};
        dfs(digits, 0);
        return result;
    }

    vector<string> letterCombinations(string digits) {
        makeDigitChar();
        return fn1(digits);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
