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
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        int ans = 0;
        for (int i : s) {
            if (s.count(i - 1)) continue;
            int cnt = 1;
            for (int j = i + 1;; j++) {
                if (!s.count(j)) break;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
}
