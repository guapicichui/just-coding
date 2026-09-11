/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30404
 *
 * [73] 矩阵置零
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row_zero = false;
        bool first_col_zero = false;
        int m = matrix.size();
        int n = matrix[0].size();

        if (matrix[0][0] == 0) {
            first_col_zero = true;
            first_row_zero = true;
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                first_row_zero = true;
                break;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0)
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0)
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
        }
        if (first_col_zero)
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        if (first_row_zero)
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */
