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
    int findKthLargest(vector<int> &nums, int k) {
        nth_element(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
        return nums[nums.size() - k];
    }
};

void solve() {
    Solution sol;
    INT(N, K);
    VI(A, N);
    print(sol.findKthLargest(A, K));
}
