/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30008
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1), *p = &head;
        ListNode *p1 = l1, *p2 = l2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        while (p1 != nullptr) {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }

        while (p2 != nullptr) {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
        return head.next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
