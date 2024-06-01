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
    int removeDuplicates(vector<int> &nums) {
        int prev = 1e8;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != prev) {
                nums[index++] = nums[i];
                prev = nums[i];
            }
        }
        return index;
    }
};

void solve() {
    Solution sol;
}
