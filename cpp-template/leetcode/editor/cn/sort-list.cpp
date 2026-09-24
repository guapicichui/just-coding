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

    ListNode* mergeSort(ListNode* dummy_head, ListNode* start, ListNode* end) {
        // base case
        if (start->next == end) {
            start->next = nullptr;
            return start;
        }

        ListNode *i = start, *j = start;
        while (j != end && j->next != end) {
            i = i->next;
            j = j->next->next;
        }
        ListNode* left_head = mergeSort(dummy_head, start, i);
        ListNode* right_head = mergeSort(dummy_head, i, end);
        // merge two list
        ListNode* p = dummy_head;
        while (left_head != nullptr && right_head != nullptr) {
            if (left_head->val <= right_head->val) {
                p->next = left_head;
                left_head = left_head->next;
            } else {
                p->next = right_head;
                right_head = right_head->next;
            }
            p = p->next;
        }
        while (left_head != nullptr) {
            p->next = left_head;
            left_head = left_head->next;
            p = p->next;
        }
        while (right_head != nullptr) {
            p->next = right_head;
            right_head = right_head->next;
            p = p->next;
        }
        return dummy_head->next;
    }

    ListNode* fn3(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* dummy_head = new ListNode(-1);
        return mergeSort(dummy_head, head, nullptr);
    }

    ListNode* split(ListNode* start, int step) {
        if (start == nullptr)
            return nullptr;
        while (step != 1 && start->next != nullptr) {
            start = start->next;
            --step;
        }
        ListNode* next_start = start->next;
        start->next = nullptr;
        return next_start;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        int len = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ++len;
            p = p->next;
        }
        for (int step = 1; step < len; step *= 2) {
            ListNode* left = head;
            ListNode dummy_head(-1);
            p = &dummy_head;
            while (left != nullptr) {
                ListNode* mid = split(left, step);
                ListNode* right = split(mid, step);
                // merge two list
                ListNode *i = left, *j = mid;
                while (i != nullptr && j != nullptr) {
                    if (i->val <= j->val) {
                        p->next = i;
                        i = i->next;
                    } else {
                        p->next = j;
                        j = j->next;
                    }
                    p = p->next;
                }
                while (i != nullptr) {
                    p->next = i;
                    i = i->next;
                    p = p->next;
                }
                while (j != nullptr) {
                    p->next = j;
                    j = j->next;
                    p = p->next;
                }
                left = right;
            }
            head = dummy_head.next;
        }
        return head;
    }

    ListNode* fn4(ListNode* head) { return mergeSort(head); }

    ListNode* sortList(ListNode* head) { return fn4(head); }
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
