/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30404
 *
 * [160] 相交链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *i = headA, *j = headB;
        while (i != j) {
            if (i == nullptr)
                i = headB;
            else
                i = i->next;
            if (j == nullptr)
                j = headA;
            else
                j = j->next;
        }
        return i;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
