/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30404
 *
 * [128] 最长连续序列
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    class UnionFind {
      private:
        vector<int> parent;
        vector<int> size;

      public:
        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // 路径压缩
            }

            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                return;
            }

            // 小集合挂到大集合上
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }

            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }

        bool connected(int x, int y) { return find(x) == find(y); }

        int getMaxSize() {
            int max_set = 0;
            for (int i = 0; i < parent.size(); ++i) {
                if (parent[i] == i) {
                    max_set = max(max_set, size[i]);
                }
            }

            return max_set;
        }
    };

  public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> id_map;
        for (int i = 0; i < nums.size(); ++i) {
            id_map[nums[i]] = i;
        }
        UnionFind union_find(nums.size());

        for (auto num : nums) {
            if (id_map.find(num - 1) != id_map.end()) {
                union_find.unite(id_map[num - 1], id_map[num]);
            }
        }

        return union_find.getMaxSize();
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */
