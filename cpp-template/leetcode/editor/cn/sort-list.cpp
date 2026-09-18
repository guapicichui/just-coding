/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30404
 *
 * [148] 排序链表
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode* fn1(ListNode* head) {
        vector<int> list;
        ListNode* i = head;
        while (i != nullptr) {
            list.push_back(i->val);
            i = i->next;
        }
        sort(list.begin(), list.end());
        i = head;
        int j = 0;
        while (i != nullptr) {
            i->val = list[j++];
            i = i->next;
        }
        return head;
    }

    ListNode* fn2(ListNode* head) {
        ListNode* i = head;
        int len = 0;
        while (i != nullptr) {
            ++len;
            i = i->next;
        }
        while (len--) {
            i = head;
            for (int j = 0; j < len; ++j) {
                if (i != nullptr && i->next != nullptr && i->val > i->next->val)
                    swap(i->val, i->next->val);
                i = i->next;
            }
        }
        return head;
    }

    ListNode* sortList(ListNode* head) { return fn2(head); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
