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
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(0, dp[i - 1]) + nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};

void solve() {
    Solution sol;
}
