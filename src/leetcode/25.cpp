#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *cur = head;
        ListNode **next = nullptr;
        ListNode *ans = nullptr;
        while (true) {
            vector<ListNode *> nodes;
            for (int i = 0; i < k; i++) {
                if (cur == nullptr) break;
                nodes.push_back(cur);
                cur = cur->next;
            }
            if (next != nullptr) {
                if (nodes.empty()) {
                    *next = nullptr;
                } else if (nodes.size() < k) {
                    *next = nodes.front();
                } else {
                    *next = nodes.back();
                }
            }
            if (nodes.size() < k) {
                if (ans == nullptr) ans = nodes.front();
                break;
            }
            for (int i = k - 1; i > 0; i--) {
                nodes[i]->next = nodes[i - 1];
            }
            next = &nodes.front()->next;
            if (ans == nullptr) {
                ans = nodes[k - 1];
            }
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    INT(N, K);
    VI(A, N);
    vector<ListNode *> nodes;
    repd(i, N) {
        if (nodes.empty()) {
            nodes.pb(new ListNode(A[i]));
        } else {
            nodes.pb(new ListNode(A[i], nodes.back()));
        }
    }
    auto head = sol.reverseKGroup(nodes.back(), K);
    vi res;
    while (head != nullptr) {
        res.pb(head->val);
        head = head->next;
    }
    print(res);
}
