/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30404
 *
 * [25] K 个一组翻转链表
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
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
    void reverseInterval(ListNode* prev, ListNode* end) {
        ListNode* p = prev->next;

        while (p->next != end) {
            ListNode* q = p->next;

            p->next = q->next;
            q->next = prev->next;
            prev->next = q;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1, head);

        ListNode* group_prev = &dummy;

        while (true) {
            ListNode* group_end = group_prev;

            for (int pace = 0; pace < k; ++pace) {
                group_end = group_end->next;

                if (group_end == nullptr)
                    return dummy.next;
            }

            // 原来的头会成为新的尾
            ListNode* group_tail = group_prev->next;

            reverseInterval(group_prev, group_end->next);

            group_prev = group_tail;
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<int> vec = std::vector<int>({1, 2, 3, 4, 5});
    ListNode* list = ListNode::createHead(vec);
    solution.reverseKGroup(list, 2);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
