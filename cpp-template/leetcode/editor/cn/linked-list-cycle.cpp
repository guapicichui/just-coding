/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30404
 *
 * [141] 环形链表
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
    bool fn1(ListNode* head) {
        ListNode *i = head, *j = head;
        while (j != nullptr && j->next != nullptr) {
            i = i->next;
            j = j->next->next;
            if (i == j)
                break;
        }
        return j != nullptr && j->next != nullptr;
    }

    bool fn2(ListNode* head) {
        if (head == nullptr)
            return false;
        std::unordered_set<ListNode*> list;
        list.insert(head);
        ListNode* i = head->next;
        while (i != nullptr) {
            if (list.find(i) != list.end())
                return true;
            list.insert(i);
            i = i->next;
        }
        return false;
    }

    bool hasCycle(ListNode* head) { return fn2(head); }
};
// @lc code=end

int main() {
    Solution solution;
    ListNode list1(2);
    ListNode list2(1, &list1);
    solution.hasCycle(&list2);
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
