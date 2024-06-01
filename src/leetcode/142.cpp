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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        bool loop = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loop = true;
                break;
            }
        }
        if (!loop) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

void solve() {
    Solution sol;
}
