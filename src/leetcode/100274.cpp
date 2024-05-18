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
    int maximumEnergy(vector<int> &energy, int k) {
        int ans = (int)-1e8;
        vector<int> m(k);
        for (int i = energy.size() - 1; i >= 0; i--) {
            m[i % k] += energy[i];
            ans = max(ans, m[i % k]);
        }
        return ans;
    }
};

void solve() {
    STR(S);
    auto v = parse_vi(S);
    INT(K);
    Solution sol;
    print(sol.maximumEnergy(v, K));
}
