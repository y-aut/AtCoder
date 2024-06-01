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
    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode *> nodes;
    //     while (head != nullptr) {
    //         if (nodes.count(head)) return true;
    //         nodes.insert(head);
    //         head = head->next;
    //     }
    //     return false;
    // }

    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

void solve() {
    Solution sol;
    LLL(a);
    print(sol.hasCycle(a));
}
