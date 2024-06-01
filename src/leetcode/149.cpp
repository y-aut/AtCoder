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
    long long get_hash(int a, int b, int c) {
        int g = gcd(abs(a), gcd(abs(b), abs(c)));
        a /= g, b /= g, c /= g;
        if (a < 0) {
            a = -a, b = -b, c = -c;
        }
        return a * 1e10 + b * 1e5 + c;
    }

public:
    int maxPoints(vector<vector<int>> &points) {
        unordered_map<long long, int> m;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                // ax + by + c = 0
                int a = points[i][1] - points[j][1];
                int b = points[j][0] - points[i][0];
                int c = -(a * points[i][0] + b * points[i][1]);
                m[get_hash(a, b, c)]++;
            }
        }
        int ans = 1;
        for (auto &&i : m) {
            ans = max(ans, (int)sqrt(i.second * 2) + 1);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    LVVI(a);
    print(sol.maxPoints(a));
}
