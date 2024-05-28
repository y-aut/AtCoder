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
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> dif;
        int cur = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            dif.push_back(cur);
            if (nums[i] % 2 == nums[i + 1] % 2) cur++;
        }
        dif.push_back(cur);
        vector<bool> ans;
        for (auto &&q : queries) {
            int d = dif[q[1]] - dif[q[0]];
            ans.push_back(d == 0);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    INT(N);
    VI(A, N);
    INT(Q1, Q2);
    vvi qs;
    qs.push_back({Q1, Q2});
    print(sol.isArraySpecial(A, qs));
}
