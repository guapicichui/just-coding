/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30404
 *
 * [3] 无重复字符的最长子串
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int func2(const string& s) {
        int last_index[256];
        fill(begin(last_index), end(last_index), -1);
        int result = 0;

        for (int i = 0, j = 0; j < s.size(); ++j) {
            unsigned char ch = s[j];
            if (last_index[ch] >= i) {
                i = last_index[ch] + 1;
            }
            last_index[ch] = j;
            result = max(result, j - i + 1);
        }

        return result;
    }

    int func1(const string& s) {
        int result = 0;
        unordered_map<char, int> sub_str_map;

        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (auto it = sub_str_map.find(s[j]);
                it != sub_str_map.end() && it->second >= i)
                i = it->second + 1;
            sub_str_map[s[j]] = j;
            result = max(result, j - i + 1);
        }

        return result;
    }

    int lengthOfLongestSubstring(string s) { return func2(s); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
