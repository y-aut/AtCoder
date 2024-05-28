#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

using ll = long long;
class Solution {
public:
    ll sumDigitDifferences(vector<int> &nums) {
        ll ans = 0;
        ll digits = to_string(nums.front()).size();
        for (ll d = 0, pow_ten = 1; d < digits; d++, pow_ten *= 10) {
            unordered_map<ll, ll> cnt;
            for (ll i = 0; i < nums.size(); i++) {
                cnt[(nums[i] / pow_ten) % 10]++;
            }
            ll tmp = 0;
            for (auto &&i : cnt) {
                tmp += i.second * (i.second - 1) / 2;
            }
            ans += nums.size() * (nums.size() - 1) / 2 - tmp;
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    INT(N);
    VI(A, N);
    print(sol.sumDigitDifferences(A));
}
