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
    int lengthOfLIS(vector<int> &nums) {
        vector<int> ary;
        for (int n : nums) {
            auto itr = lower_bound(ary.begin(), ary.end(), n);
            if (itr == ary.end()) {
                ary.push_back(n);
            } else {
                *itr = n;
            }
        }
        return ary.size();
    }
};

void solve() {
    Solution sol;
    LVI(a);
    print(sol.lengthOfLIS(a));
}
