/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30404
 *
 * [146] LRU 缓存
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class LRUCache {
  private:
    struct Node {
        int key{};
        int value{};
        Node* prev{};
        Node* next{};
    };

    int capacity{};
    Node dummy_head{};
    Node dummy_tail{};
    unordered_map<int, Node*> cache;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void addFront(Node* node) {
        Node* temp = dummy_head.next;
        dummy_head.next = node;
        node->next = temp;
        node->prev = &dummy_head;
        temp->prev = node;
    }

    void moveFront(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addFront(node);
    }

  public:
    LRUCache(int capacity) : capacity(capacity) {
        dummy_head.next = &dummy_tail;
        dummy_tail.prev = &dummy_head;
    }

    int get(int key) {
        if (auto it = cache.find(key); it != cache.end()) {
            moveFront(it->second);
            return it->second->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (auto it = cache.find(key); it != cache.end()) {
            it->second->value = value;
            moveFront(it->second);
        } else {
            Node* temp = new Node{key, value, nullptr, nullptr};
            if (cache.size() >= capacity) {
                cache.erase(dummy_tail.prev->key);
                remove(dummy_tail.prev);
            }
            addFront(temp);
            cache.insert({key, temp});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
//
["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]\n
// @lcpr case=end

 */
