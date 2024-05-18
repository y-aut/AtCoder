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
    int trapRainWater(vector<vector<int>> &heightMap) {
        int height = heightMap.size();
        int width = heightMap[0].size();

        vector<int> dx{1, 0, -1, 0};
        vector<int> dy{0, 1, 0, -1};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<bool>> visited(height, vector<bool>(width, false));

        for (int i = 0; i < height; i++) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][width - 1], i, width - 1);
            visited[i][0] = visited[i][width - 1] = true;
        }
        for (int i = 1; i < width - 1; i++) {
            pq.emplace(heightMap[0][i], 0, i);
            pq.emplace(heightMap[height - 1][i], height - 1, i);
            visited[0][i] = visited[height - 1][i] = true;
        }

        int ans = 0;
        int max_height = -1;
        while (!pq.empty()) {
            auto [v, y, x] = pq.top();
            pq.pop();
            if (v > max_height) {
                max_height = v;
            } else {
                ans += max_height - v;
            }
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (!(0 <= ny && ny < height)) continue;
                if (!(0 <= nx && nx < width)) continue;
                if (visited[ny][nx]) continue;
                pq.emplace(heightMap[ny][nx], ny, nx);
                visited[ny][nx] = true;
            }
        }
        return ans;
    }
};

void solve() {
    STR(S);
    auto v = parse_vvi(S);
    Solution sol;
    print(sol.trapRainWater(v));
}
