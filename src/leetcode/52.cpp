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
    // int dfs(int n, vector<pair<int, int>> &queens) {
    //     if (queens.size() == n) return 1;
    //     int ans = 0;
    //     for (int i = queens.empty() ? 0 : queens.back().first * n + queens.back().second; i < n * n; i++) {
    //         int y = i / n, x = i % n;
    //         bool effect = false;
    //         for (auto [qy, qx] : queens) {
    //             if (qy == y || qx == x || abs(qy - y) == abs(qx - x)) {
    //                 effect = true;
    //                 break;
    //             }
    //         }
    //         if (effect) continue;
    //         queens.emplace_back(y, x);
    //         ans += dfs(n, queens);
    //         queens.pop_back();
    //     }
    //     return ans;
    // }

    int dfs(int n, int cnt, vector<bool> &col, vector<bool> &dig, vector<bool> &crdig) {
        if (cnt == n) return 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (col[i] || dig[i + cnt] || crdig[cnt - i + n - 1]) continue;
            col[i] = dig[i + cnt] = crdig[cnt - i + n - 1] = true;
            ans += dfs(n, cnt + 1, col, dig, crdig);
            col[i] = dig[i + cnt] = crdig[cnt - i + n - 1] = false;
        }
        return ans;
    }

public:
    int totalNQueens(int n) {
        vector<bool> col(n);
        vector<bool> dig(n * 2 - 1);
        vector<bool> crdig(n * 2 - 1);
        return dfs(n, 0, col, dig, crdig);
    }
};

void solve() {
    Solution sol;
    INT(N);
    print(sol.totalNQueens(N));
}
