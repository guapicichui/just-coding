/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30404
 *
 * [49] 字母异位词分组
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  private:
    std::string getAnagramKey(const string& str) {
        std::array<int, 26> char_count{};
        for (char c : str) {
            ++char_count[c - 'a'];
        }
        std::string key;
        for (auto elem : char_count) {
            key += '#';
            key += std::to_string(elem);
        }
        return key;
    }

  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, vector<string>> groups;
        for (auto str : strs) {
            auto str_key = getAnagramKey(str);
            groups[str_key].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& pair_elem : groups) {
            result.push_back(std::move(pair_elem.second));
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["eat","tea","tan","ate","nat","bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
