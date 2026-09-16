/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30404
 *
 * [234] 回文链表
 */

#include "../common/ListNode.cpp"
// #include "../common/TreeNode.cpp"
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


// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* p = head;
        while (p->next != nullptr) {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = head;
            head = q;
        }
        return head;
    }

    bool fn1(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        int len = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ++len;
            p = p->next;
        }
        int half_len = len / 2;
        p = head;
        for (int i = 0; i < half_len; ++i) {
            p = p->next;
        }
        if (len % 2 == 1)
            p = p->next;
        p = reverseList(p);
        while (p != nullptr) {
            if (head->val != p->val)
                return false;
            head = head->next;
            p = p->next;
        }
        return true;
    }

    bool fn2(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        int len = 0;
        ListNode* p = head;
        std::vector<int> half_list;
        while (p != nullptr) {
            ++len;
            p = p->next;
        }
        int half_len = len / 2;
        p = head;
        for (int i = 0; i < half_len; ++i) {
            half_list.push_back(p->val);
            p = p->next;
        }
        // half_list.pop_back();
        if (len % 2 == 1)
            p = p->next;
        for (int i = half_list.size() - 1; i >= 0; --i) {
            if (half_list[i] != p->val)
                return false;
            p = p->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) { return fn2(head); }
};
// @lc code=end


int main() {

    ListNode list1(1);
    ListNode list2(2, &list1);
    ListNode list3(2, &list2);
    ListNode list4(1, &list3);

    Solution solution;
    ListNode* head = &list4;
    solution.isPalindrome(head);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
