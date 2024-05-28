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
    int waysToReachStair(int k) {
        // 0001 -> 0010 -> 0100 -> 1000
        vector<int> ary{2, 4, 4, 3, 2, 4};
        if (k < ary.size()) return ary[k];
        int left = 0;
        for (int i = 1; i < k; left++) i <<= 1;
        int dif = (1 << left) - k;
        if (dif < 0 || left + 1 < dif) return 0;
        long long ans = 1;
        set<int> to_div;
        for (int i = 2; i <= dif; i++) to_div.insert(i);
        for (int i = left + 1, j = 0; j < dif; i--, j++) {
            ans *= i;
            vector<int> divided;
            for (int d : to_div) {
                if (ans % d == 0) {
                    ans /= d;
                    divided.push_back(d);
                }
            }
            for (int d : divided) to_div.erase(d);
        }
        for (int d : to_div) ans /= d;
        return ans;
    }
};

void solve() {
    Solution sol;
    INT(K);
    print(sol.waysToReachStair(K));
}
