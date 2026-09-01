/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30404
 *
 * [438] 找到字符串中所有字母异位词
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> fn1(const string& s, const string& p) {
        vector<int> result;
        array<int, 256> char_nums{};
        if (s.size() < p.size())
            return result;
        for (auto ch : p) {
            ++char_nums[static_cast<int>(ch) - static_cast<int>('a')];
        }
        for (int i = 0, j = p.size() - 1; j < s.size(); ++i, ++j) {
            array<int, 256> sub_char_nums{};
            for (int k = i; k <= j; ++k) {
                ++sub_char_nums[static_cast<int>(s[k]) - static_cast<int>('a')];
            }
            bool is_anagram = true;
            for (int k = 0; k < 256; ++k) {
                if (char_nums[k] != sub_char_nums[k]) {
                    is_anagram = false;
                    break;
                }
            }
            if (is_anagram)
                result.push_back(i);
        }
        return result;
    }

    vector<int> fn2(const string& s, const string& p) {
        vector<int> res;
        if (s.size() < p.size())
            return res;

        array<int, 256> char_nums{};
        for (auto ch : p) {
            ++char_nums[static_cast<int>(ch) - static_cast<int>('a')];
        }

        array<int, 256> sub_char_nums{};
        for (int k = 0; k < p.size(); ++k) {
            ++sub_char_nums[static_cast<int>(s[k]) - static_cast<int>('a')];
        }

        if (sub_char_nums == char_nums)
            res.push_back(0);

        for (int i = 1, j = p.size(); j < s.size(); ++i, ++j) {
            --sub_char_nums[static_cast<int>(s[i - 1]) - static_cast<int>('a')];
            ++sub_char_nums[static_cast<int>(s[j]) - static_cast<int>('a')];

            if (sub_char_nums == char_nums)
                res.push_back(i);
        }

        return res;
    }
    vector<int> findAnagrams(string s, string p) { return fn2(s, p); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
