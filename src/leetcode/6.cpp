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
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> row(numRows);
        for (int i = 0; i < s.size(); i++) {
            int mod = i % (2 * numRows - 2);
            if (mod < numRows) row[mod] += s[i];
            else row[2 * numRows - 2 - mod] += s[i];
        }
        ostringstream os;
        copy(row.begin(), row.end(), ostream_iterator<string>(os));
        return os.str();
    }
};

/*
    n >= 2:
    period: 2n-2
    for i<n, row[i]
    for n<=i<2n-2, row[2n-i-2]
*/

void solve() {
    Solution sol;
    STR(S);
    INT(R);
    print(sol.convert(S, R));
}
