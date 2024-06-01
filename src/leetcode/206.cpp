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
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return nullptr;
        auto cur = new ListNode(head->val);
        while (head->next != nullptr) {
            auto next = new ListNode(head->next->val);
            next->next = cur;
            cur = next;
            head = head->next;
        }
        return cur;
    }
};

void solve() {
    Solution sol;
    LLL(a);
    lprint(sol.reverseList(a));
}
