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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string s(strs[i]);
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto &&i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
}
