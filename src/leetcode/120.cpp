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
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> dp{triangle[0][0]};
        for (int i = 1; i < triangle.size(); i++) {
            vector<int> nxt(i + 1, 1e8);
            for (int j = 0; j < dp.size(); j++) {
                nxt[j] = min(nxt[j], dp[j] + triangle[i][j]);
                nxt[j + 1] = min(nxt[j + 1], dp[j] + triangle[i][j + 1]);
            }
            dp = move(nxt);
        }
        return *min_element(dp.begin(), dp.end());
    }
};

void solve() {
    Solution sol;
    STR(S);
    auto t = parse_vvi(S);
    print(sol.minimumTotal(t));
}
