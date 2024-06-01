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
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (st.top() == '(' && c == ')' || st.top() == '{' && c == '}' || st.top() == '[' && c == ']') {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};

void solve() {
    Solution sol;
}
