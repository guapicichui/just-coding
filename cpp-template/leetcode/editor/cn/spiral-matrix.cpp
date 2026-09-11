/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30404
 *
 * [54] 螺旋矩阵
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
    vector<int> fn1(const vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int N = (min(m, n) + 1) / 2;
        int i = 0, j = 0;
        vector<int> result;

        for (int x = 0; x < N; ++x) {
            int len1 = n - 2 * x - 1;
            int len2 = m - 2 * x - 1;
            i = x, j = x;
            if (len1 == 0) {
                for (int a = 0; a <= len2; ++a)
                    result.push_back(matrix[i++][j]);
                return result;
            }

            if (len2 == 0) {
                for (int a = 0; a <= len1; ++a)
                    result.push_back(matrix[i][j++]);
                return result;
            }
            for (int a = 0; a < len1; ++a) {
                result.push_back(matrix[i][j++]);
            }
            for (int a = 0; a < len2; ++a) {
                result.push_back(matrix[i++][j]);
            }
            for (int a = 0; a < len1; ++a) {
                result.push_back(matrix[i][j--]);
            }
            for (int a = 0; a < len2; ++a) {
                result.push_back(matrix[i--][j]);
            }
        }

        return result;
    }

    vector<int> fn2(const vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int N = (min(m, n) + 1) / 2;

        for (int x = 0; x < N; ++x) {
            int top = x, bottom = m - x - 1, left = x, right = n - x - 1;

            if (top == bottom) {
                for (int j = left; j <= right; ++j) {
                    result.push_back(matrix[top][j]);
                }
                return result;
            }

            if (left == right) {
                for (int i = top; i <= bottom; ++i) {
                    result.push_back(matrix[i][left]);
                }
                return result;
            }

            for (int j = left; j < right; ++j) {
                result.push_back(matrix[top][j]);
            }
            for (int i = top; i < bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            for (int j = right; j > left; --j) {
                result.push_back(matrix[bottom][j]);
            }
            for (int i = bottom; i > top; --i) {
                result.push_back(matrix[i][left]);
            }
        }
        return result;
    }

    vector<int> fn3(const vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        vector<int> result;

        while (top <= bottom && left <= right) {
            if (top == bottom) {
                for (int j = left; j <= right; ++j)
                    result.push_back(matrix[top][j]);
                return result;
            }
            if (left == right) {
                for (int i = top; i <= bottom; ++i)
                    result.push_back(matrix[i][left]);
                return result;
            }

            for (int j = left; j < right; ++j)
                result.push_back(matrix[top][j]);
            for (int i = top; i < bottom; ++i)
                result.push_back(matrix[i][right]);
            for (int j = right; j > left; --j)
                result.push_back(matrix[bottom][j]);
            for (int i = bottom; i > top; --i)
                result.push_back(matrix[i][left]);

            top++;
            bottom--;
            left++;
            right--;
        }
        return result;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) { return fn3(matrix); }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> matrix{{6, 9, 7}};
    solution.spiralOrder(matrix);
    // your test code here
}

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */
