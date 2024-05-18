/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto hd = new ListNode();
        auto cur = hd;
        ListNode *prev = nullptr;
        bool carry = false;
        while (true) {
            if (l1 == nullptr && l2 == nullptr) {
                if (carry) {
                    cur->val = 1;
                    prev->next = cur;
                }
                break;
            }

            int val = carry;
            if (l1 != nullptr) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val += l2->val;
                l2 = l2->next;
            }
            if (prev != nullptr) {
                prev->next = cur;
            }
            cur->val = val % 10;
            carry = val >= 10;
            prev = cur;
            cur = new ListNode();
        }
        return hd;
    }
};