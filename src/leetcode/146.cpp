#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

class LRUCache {
    struct Node {
        int key;
        int value;
        Node *prev = nullptr;
        Node *next = nullptr;

        Node() : key(0), value(0) {}
        Node(int _key, int _value) : key(_key), value(_value) {}
    };

    unordered_map<int, Node *> nodes;
    Node *head, *tail;
    int cap;

    void push_front(Node *node) {
        node->prev = head;
        node->next = head->next;
        node->prev->next = node->next->prev = node;
    }

    Node *pop_back() {
        auto node = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        return node;
    }

    void erase(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!nodes.count(key)) return -1;
        erase(nodes[key]);
        push_front(nodes[key]);
        return nodes[key]->value;
    }

    void put(int key, int value) {
        if (nodes.count(key)) {
            nodes[key]->value = value;
            erase(nodes[key]);
        } else {
            if (nodes.size() == cap) {
                auto node = pop_back();
                nodes.erase(node->key);
                delete node;
            }
            nodes[key] = new Node(key, value);
        }
        push_front(nodes[key]);
    }
};

/*
    linked list & hashmap
    get(int key) -> move to last & return hashmap[key]
    put(int key, int value) -> pop front & add to last
*/

void solve() {
    LRUCache cache(1);
    cache.put(1, 1);
    cache.put(2, 2);
    print(cache.get(1));
    cache.put(3, 3);
    print(cache.get(2));
    cache.put(4, 4);
    print(cache.get(1));
    print(cache.get(3));
    print(cache.get(4));
}
