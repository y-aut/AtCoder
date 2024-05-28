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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        dp[0][0] = 0;
        for (int i = 0; i <= word1.size(); i++) {
            for (int j = 0; j <= word2.size(); j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + 1;
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]),
                                   min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
        return dp.back().back();
    }
};

void solve() {
    Solution sol;
    STR(S, T);
    print(sol.minDistance(S, T));
}
