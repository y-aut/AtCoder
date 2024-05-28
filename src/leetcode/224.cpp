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
    int calculate(string s) {
        stack<int> st;
        int ans = 0, sign = 1, val = 0;
        for (char c : s) {
            switch (c) {
                case ' ':
                    continue;
                case '(':
                    st.push(ans);
                    st.push(sign);
                    ans = 0;
                    sign = 1;
                    val = 0;
                    continue;
                case ')': {
                    ans += val * sign;
                    int top_sign = st.top();
                    st.pop();
                    int top_cur = st.top();
                    st.pop();
                    ans = ans * top_sign + top_cur;
                    val = 0;
                    break;
                }
                case '+':
                    ans += val * sign;
                    sign = 1;
                    val = 0;
                    break;
                case '-':
                    ans += val * sign;
                    sign = -1;
                    val = 0;
                    break;
                default:
                    val *= 10;
                    val += c - '0';
                    break;
            }
        }
        ans += val * sign;
        return ans;
    }
};

void solve() {
    Solution sol;
    string S;
    getline(cin, S);
    print(sol.calculate(S));
}
