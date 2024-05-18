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
    int maxScore(vector<vector<int>> &grid) {
        int ans = (int)-1e8;
        vector<int> mn(grid[0].size(), (int)1e8);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, grid[i][j] - mn[j]);
                mn[j] = min(mn[j], grid[i][j]);
                if (j != grid[0].size() - 1) {
                    mn[j + 1] = min(mn[j + 1], mn[j]);
                }
            }
        }
        return ans;
    }
};

void solve() {
    Solution sol;
}
