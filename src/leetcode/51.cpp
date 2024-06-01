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
    vector<vector<string>> ans;

    void dfs(int n, vector<int> &queens, vector<bool> &col, vector<bool> &dig, vector<bool> &crdig) {
        if (queens.size() == n) {
            ans.push_back(vector<string>(n, string(n, '.')));
            for (int i = 0; i < n; i++) {
                ans.back()[i][queens[i]] = 'Q';
            }
        }
        for (int i = 0; i < n; i++) {
            if (col[i] || dig[i + queens.size()] || crdig[queens.size() - i + n - 1]) continue;
            col[i] = dig[i + queens.size()] = crdig[queens.size() - i + n - 1] = true;
            queens.push_back(i);
            dfs(n, queens, col, dig, crdig);
            queens.pop_back();
            col[i] = dig[i + queens.size()] = crdig[queens.size() - i + n - 1] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens;
        vector<bool> col(n);
        vector<bool> dig(n * 2 - 1);
        vector<bool> crdig(n * 2 - 1);
        dfs(n, queens, col, dig, crdig);
        return ans;
    }
};

void solve() {
    Solution sol;
    INT(N);
    print(sol.solveNQueens(N));
}
