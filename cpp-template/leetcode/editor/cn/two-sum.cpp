/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30404
 *
 * [1] 两数之和
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
    void printVec(const std::vector<int>& nums) {
        for (auto num : nums) {
            std::cout << num << ",";
        }
        std::cout << std::endl;
    }

    vector<int> twoSum1(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> require_num_map;
        for (int i = 0; i < nums.size(); i++) {
            int b = target - nums[i];
            if (require_num_map.find(nums[i]) != require_num_map.end()) {
                result.push_back(require_num_map[nums[i]]);
                result.push_back(i);
                // printVec(result);
                return result;
            }
            require_num_map.insert(std::pair<int, int>(b, i));
        }
        return result;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        struct IndexNum {
            int index{};
            long long value{};
        };
        vector<IndexNum> index_nums{nums.size()};
        for (int i = 0; i < nums.size(); ++i) {
            index_nums[i].index = i;
            index_nums[i].value = nums[i];
        }

        sort(index_nums.begin(), index_nums.end(),
             [](const IndexNum& index_num1, const IndexNum& index_num2) {
                 return index_num1.value < index_num2.value;
             });
        for (int i = 0, j = static_cast<int>(index_nums.size()) - 1; i < j;) {
            long long cur_sum = index_nums[i].value + index_nums[j].value;
            if (cur_sum == target) {
                return {index_nums[i].index, index_nums[j].index};
            } else if (cur_sum > target)
                --j;
            else
                ++i;
        }
        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSum2(nums, target);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
