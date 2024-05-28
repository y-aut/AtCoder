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
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (citations.size() - i > citations[i]) return citations.size() - i - 1;
        }
        return citations.size();
    }
};

void solve() {
    Solution sol;
    INT(N);
    VI(A, N);
    print(sol.hIndex(A));
}
