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
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    ans += abs(i - j);
                }
            }
        }
        return ans;
    }
};

void solve() {
    Solution sol;
}
