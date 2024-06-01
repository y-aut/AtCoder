#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

class Solution {
    ListNode *merge(ListNode *a, ListNode *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode *head;
        if (a->val <= b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }
        auto prev = head;
        while (a != nullptr && b != nullptr) {
            ListNode *cur;
            if (a->val <= b->val) {
                cur = a;
                a = a->next;
            } else {
                cur = b;
                b = b->next;
            }
            prev->next = cur;
            prev = cur;
        }
        if (a == nullptr) swap(a, b);
        while (a != nullptr) {
            prev->next = a;
            prev = a;
            a = a->next;
        }
        return head;
    }

    ListNode *mergeRange(const vector<ListNode *> &lists, int l, int r) {
        if (r - l == 1) return lists[l];
        int mid = (l + r) / 2;
        auto a = mergeRange(lists, l, mid);
        auto b = mergeRange(lists, mid, r);
        return merge(a, b);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size());
    }
};

void solve() {
    Solution sol;
    vector<ListNode *> lists;
    LVVI(v);
    repi(i, v) lists.pb(parse_lll(i));
    lprint(sol.mergeKLists(lists));
}
