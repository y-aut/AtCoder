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
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty()) return 0;
        int p1 = 0, p2 = nums.size() - 1;
        while (true) {
            while (p2 >= 0 && nums[p2] == val) p2--;
            while (p1 < p2 && nums[p1] != val) p1++;
            if (p1 >= p2) return p2 + 1;
            swap(nums[p1], nums[p2]);
        }
    }
};

void solve() {
    Solution sol;
    LVI(a);
    INT(v);
    print(sol.removeElement(a, v));
    print(a);
}
