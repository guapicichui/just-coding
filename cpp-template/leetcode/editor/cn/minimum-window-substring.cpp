/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30404
 *
 * [76] 最小覆盖子串
 */

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }
        array<int, 256> t_need{};
        array<int, 256> t_window{};
        int t_need_size = 0;
        int t_window_size = 0;

        int result_begin = 0;
        int result_len = INT32_MAX;
        for (auto ch : t) {
            if (t_need[static_cast<int>(ch)]++ == 0) {
                ++t_need_size;
            }
        }

        for (int i = 0, j = 0; j < s.size();) {
            if (t_need[s[j]] > 0) {
                if (++t_window[s[j]] == t_need[s[j]])
                    ++t_window_size;
            }

            while (t_window_size == t_need_size) {
                if (j - i + 1 < result_len) {
                    result_begin = i;
                    result_len = j - i + 1;
                }
                char ch = s[i];
                if (t_need[ch] > 0) {
                    if (t_window[ch]-- == t_need[ch])
                        --t_window_size;
                }
                ++i;
            }

            ++j;
        }
        if (result_len == INT32_MAX)
            return "";
        return s.substr(result_begin, result_len);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
