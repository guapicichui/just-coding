/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30404
 *
 * [142] 环形链表 II
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* fn1(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        std::unordered_set<ListNode*> list;
        list.insert(head);
        ListNode* i = head->next;
        while (i != nullptr) {
            if (list.find(i) != list.end())
                return i;
            list.insert(i);
            i = i->next;
        }
        return nullptr;
    }

    ListNode* fn2(ListNode* head) {
        ListNode *i = head, *j = head;
        while (j != nullptr && j->next != nullptr) {
            i = i->next;
            j = j->next->next;
            if (i == j)
                break;
        }
        if (j == nullptr || j->next == nullptr)
            return nullptr;

        i = head;
        while (i != j) {
            i = i->next;
            j = j->next;
        }
        return i;
    }

    ListNode* detectCycle(ListNode* head) { return fn2(head); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
