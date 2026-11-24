/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30404
 *
 * [79] 单词搜索
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
    vector<vector<int>> offset{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  public:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j,
             int index) {
        if (i >= board.size() || i < 0)
            return false;
        if (j >= board[i].size() || j < 0)
            return false;
        if (board[i][j] == '-')
            return false;

        auto next_index = index;
        if (board[i][j] == word[index])
            ++next_index;
        else
            return false;

        if (index == word.size() - 1)
            return true;
        auto temp_char = board[i][j];
        board[i][j] = '-';
        for (const auto& item : offset) {
            if (dfs(board, word, i + item[0], j + item[1], next_index)) {
                board[i][j] = temp_char;
                return true;
            }
        }
        board[i][j] = temp_char;
        return false;
    }

    bool fn1(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) { return fn1(board, word); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
