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
    void dfs(const string &digits, int index, const vector<string> &letters, string &cur, vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (auto c : letters[digits[index] - '2']) {
            cur.push_back(c);
            dfs(digits, index + 1, letters, cur, ans);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur;
        vector<string> ans;
        if (digits.empty()) return ans;
        dfs(digits, 0, letters, cur, ans);
        return ans;
    }
};

void solve() {
    Solution sol;
    STR(S);
    print(sol.letterCombinations(S));
}
