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
    int longestValidParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty() || s[st.top()] == ')') {
                    st.push(i);
                } else {
                    st.pop();
                }
            }
        }
        int ans = 0, prev = s.size();
        while (!st.empty()) {
            ans = max(ans, prev - st.top() - 1);
            prev = st.top();
            st.pop();
        }
        ans = max(ans, prev);
        return ans;
    }
};

/*
    dp[i]: start index when count('(') - count(')') == i

    dp[n][p]: stores count('(') - count(')') when start index == p
    (():
        dp[0][0] == 0
        dp[1][0] == 1, dp[1][1] == 0
        dp[2][0] == 2, dp[2][1] == 1, dp[2][2] == 0

    )()()):
        [0, -1, 0, -1, 0, -1, -2]

        [0, 0, 0, 0, 0, 0, 0]
*/

void solve() {
    Solution sol;
    STR(S);
    print(sol.longestValidParentheses(S));
}
