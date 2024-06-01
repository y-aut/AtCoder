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
    int numSteps(string s) {
        int ones = 0, last_one = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones++;
                last_one = i;
            }
        }
        if (ones == 1) return s.size() - 1;
        return s.size() + last_one - ones + 2;
    }
};

void solve() {
    Solution sol;
    STR(S);
    print(sol.numSteps(S));
}
