#ifndef TEMPLATE_H
#include "template.hpp"
#endif

#define LVI(a) auto a = in_lvi()
#define LVVI(a) auto a = in_lvvi()
#define LLL(a) auto a = in_lll()
#define LBT(a) auto a = in_lbt()

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : val(x), left(left), right(right) {}
};

inline void lprint(const ListNode *v) {
    vi res;
    while (v != nullptr) {
        res.pb(v->val);
        v = v->next;
    }
    print(res);
}

pair<string, string> parenthesis{"({[", ")}]"};

vs split(const string &s, char delim) {
    vs elems;
    string item;
    repi(c, s) {
        if (c == delim) {
            elems.pb(item);
            item.clear();
        } else {
            item += c;
        }
    }
    elems.pb(item);
    return elems;
}

// 括弧を考慮する
vs split_with_parenthesis(const string &s, char delim) {
    vs elems;
    string item;
    stack<size_t> par;
    repi(c, s) {
        auto pos = parenthesis.first.find(c);
        if (pos != string::npos) {
            par.push(pos);
        } else {
            pos = parenthesis.second.find(c);
            if (pos != string::npos) {
                assert(!par.empty() && pos == par.top());
                par.pop();
            }
        }

        if (par.empty() && c == delim) {
            elems.pb(item);
            item.clear();
        } else {
            item += c;
        }
    }
    elems.pb(item);
    return elems;
}

vi parse_vi(const string &s) {
    vi ans;
    if (s.size() == 2) return ans;
    repi(i, split(s.substr(1, s.size() - 2), ',')) {
        ans.pb(stoi(i));
    }
    return ans;
}

vvi parse_vvi(const string &s) {
    vvi ans;
    if (s.size() == 2) return ans;
    repi(i, split_with_parenthesis(s.substr(1, s.size() - 2), ',')) {
        ans.pb(vi());
        if (i.size() == 2) continue;
        repi(j, split(i.substr(1, i.size() - 2), ',')) {
            ans.back().pb(stoi(j));
        }
    }
    return ans;
}

// leetcode linked list
ListNode *parse_lll(const vi &v) {
    if (v.empty()) return nullptr;
    auto head = new ListNode(v[0]);
    auto cur = head;
    rep(i, 1, v.size()) {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    return head;
}

// leetcode binary tree
BinaryTreeNode *parse_lbt(const string &s) {
    if (s.size() == 2) return nullptr;
    vs words = split(s.substr(1, s.size() - 2), ',');
    vector<BinaryTreeNode *> nodes(words.size());
    rep(i, words.size()) {
        if (words[i] == "null") continue;
        int v = stoi(words[i]);
        nodes[i] = new BinaryTreeNode(v);
        if (i != 0) {
            if (i & 1) {
                nodes[(i + 1) / 2 - 1]->left = nodes[i];
            } else {
                nodes[(i + 1) / 2 - 1]->right = nodes[i];
            }
        }
    }
    return nodes[0];
}

vi in_lvi() {
    return parse_vi(in_str());
}

vvi in_lvvi() {
    return parse_vvi(in_str());
}

ListNode *in_lll() {
    return parse_lll(in_lvi());
}

BinaryTreeNode *in_lbt() {
    return parse_lbt(in_str());
}
