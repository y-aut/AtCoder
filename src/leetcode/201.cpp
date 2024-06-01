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
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (left >> i == right >> i && (left & (1 << i))) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};

/*
    a_31, a_30, a_29, ... , a_0
    a_i = 0 if a_31 , ... , a_{i-1}
*/

void solve() {
    Solution sol;
    INT(l, r);
    print(sol.rangeBitwiseAnd(l, r));
}
