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
    int maxProfit(vector<int> &prices) {
        vector<vector<int>> dp(3, vector<int>(2, -1e8));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[2][0] = max(dp[2][0], dp[1][1] + prices[i]);
            dp[1][1] = max(dp[1][1], dp[1][0] - prices[i]);
            dp[1][0] = max(dp[1][0], dp[0][1] + prices[i]);
            dp[0][1] = max(dp[0][1], dp[0][0] - prices[i]);
        }
        return max(dp[0][0], max(dp[1][0], dp[2][0]));
    }
};

void solve() {
    Solution sol;
    LVI(a);
    print(sol.maxProfit(a));
}
