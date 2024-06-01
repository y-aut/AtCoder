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
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> cur{(int)-1e8, (int)-1e8};
        for (auto &&i : intervals) {
            if (i[0] <= cur[1]) {
                cur[1] = max(cur[1], i[1]);
            } else {
                if (cur[0] != -1e8) {
                    ans.push_back(cur);
                }
                cur = i;
            }
        }
        if (cur[0] != -1e8) {
            ans.push_back(cur);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    LVVI(a);
    print(sol.merge(a));
}
