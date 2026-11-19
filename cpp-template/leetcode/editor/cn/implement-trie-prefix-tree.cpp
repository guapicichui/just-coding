/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30404
 *
 * [208] 实现 Trie (前缀树)
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Trie {
  private:
    struct TrieNode {
        TrieNode* children[26]{};
        bool is_end{};
    };

    TrieNode* root;

  public:
    Trie() { root = new TrieNode{}; }

    void insert(string word) {
        auto cur = root;
        auto index = 0;
        while (cur && index < word.size() && cur->children[word[index] - 'a']) {
            cur = cur->children[word[index++] - 'a'];
        }

        for (int i = index; i < word.size(); ++i) {
            cur->children[word[i] - 'a'] = new TrieNode{};
            cur = cur->children[word[i] - 'a'];
        }
        cur->is_end = true;
    }

    bool search(string word) {
        auto cur = root;
        auto index = 0;
        while (cur && index < word.size() && cur->children[word[index] - 'a']) {
            cur = cur->children[word[index++] - 'a'];
        }
        return index == word.size() && cur != nullptr && cur->is_end;
    }

    bool startsWith(string prefix) {
        auto cur = root;
        auto index = 0;
        while (cur && index < prefix.size() && cur->children[prefix[index] - 'a']) {
            cur = cur->children[prefix[index++] - 'a'];
        }
        return index == prefix.size() && cur != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
//
["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]\n
// @lcpr case=end

 */
