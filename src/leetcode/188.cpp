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
    int maxProfit(int k, vector<int> &prices) {
        vector<vector<int>> dp(k + 1, vector<int>(2, -1e8));
        dp[0][0] = 0;
        for (int p : prices) {
            for (int i = 0; i < k; i++) {
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + p);
                dp[i][1] = max(dp[i][1], dp[i][0] - p);
            }
        }
        int ans = 0;
        for (int i = 0; i < k + 1; i++) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    INT(k);
    LVI(a);
    print(sol.maxProfit(k, a));
}
