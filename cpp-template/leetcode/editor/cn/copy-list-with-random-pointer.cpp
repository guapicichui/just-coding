/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30404
 *
 * [138] 随机链表的复制
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
  public:
    Node* fn1(Node* head) {
        std::unordered_map<Node*, Node*> random_node;
        Node *i = head, new_head(-1), *p = &new_head;
        while (i != nullptr) {
            Node* temp = new Node(i->val);
            random_node.insert({i, temp});
            p->next = temp;
            p = p->next;
            i = i->next;
        }

        i = head, p = new_head.next;
        while (i != nullptr) {
            if (random_node.find(i->random) != random_node.end()) {
                p->random = random_node[i->random];
            }
            i = i->next;
            p = p->next;
        }

        return new_head.next;
    }

    Node* fn2(Node* head) {
        Node* i = head;
        while (i != nullptr) {
            Node* temp = new Node(i->val);
            temp->next = i->next;
            i->next = temp;
            i = i->next->next;
        }
        i = head;
        while (i != nullptr && i->next != nullptr) {
            i->next->random = i->random ? i->random->next : nullptr;
            i = i->next->next;
        }
        i = head;
        Node new_head(-1), *p = &new_head;
        while (i != nullptr && i->next != nullptr) {
            Node* q = i->next;
            i->next = q->next;
            p->next = q;

            i = i->next;
            p = p->next;
        }
        return new_head.next;
    }

    Node* copyRandomList(Node* head) { return fn2(head); }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */
