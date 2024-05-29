#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

struct Node {
    char c = 0;
    int count = 0;
    int descendant = 0;
    Node *children[26] = {};

    Node() {}
    Node(char _c) : c(_c) {}
};

class Trie {
private:
    Node root;

public:
    Trie() {
    }

    void insert(string word) {
        Node *cur = &root;
        for (auto c : word) {
            cur->descendant++;
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new Node(c - 'a');
            }
            cur = cur->children[c - 'a'];
        }
        cur->count++;
    }

    bool search(string word) {
        Node *cur = &root;
        for (auto c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->count > 0;
    }

    bool startsWith(string prefix) {
        Node *cur = &root;
        for (auto c : prefix) {
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->count > 0 || cur->descendant > 0;
    }
};

void solve() {
    Trie trie;
    trie.insert("apple");
    print(trie.search("apple"));
}
