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
    int equalSubstring(string s, string t, int maxCost) {
        int p1 = 0, p2 = 0, curCost = 0, ans = 0;
        while (p2 < s.size()) {
            if (curCost + abs(s[p2] - t[p2]) <= maxCost) {
                curCost += abs(s[p2] - t[p2]);
                p2++;
                ans = max(ans, p2 - p1);
            } else {
                curCost -= abs(s[p1] - t[p1]);
                p1++;
            }
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    STR(S, T);
    INT(C);
    print(sol.equalSubstring(S, T, C));
}
