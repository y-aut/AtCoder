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
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            if (i >= n - i - 1) break;
            for (int j = i; j < n - i - 1; j++) {
                // rotate [i][j], [j][n-i-1], [n-i-1][n-j-1], [n-j-1][i]
                swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
                swap(matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]);
                swap(matrix[j][n - i - 1], matrix[i][j]);
            }
        }
    }
};

void solve() {
    Solution sol;
    STR(S);
    auto m = parse_vvi(S);
    sol.rotate(m);
    print(m);
}
