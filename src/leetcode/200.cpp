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
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid.front().size();
        int ans = 0;
        vector<int> dif{0, 1, 0, -1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                ans++;
                q.emplace(i, j);
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [ci, cj] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int ni = ci + dif[k], nj = cj + dif[k + 1];
                        if (!(0 <= ni && ni < m && 0 <= nj && nj < n)) continue;
                        if (visited[ni][nj] || grid[ni][nj] == '0') continue;
                        q.emplace(ni, nj);
                        visited[ni][nj] = true;
                    }
                }
            }
        }
        return ans;
    }
};

/*
    BFS
*/

void solve() {
    Solution sol;
    vector<vc> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    print(sol.numIslands(grid));
}
