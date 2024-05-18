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
    int best = 1e8;
    vector<int> ans;

    void dfs(const vector<int> &nums, vector<int> &cur, int cur_score, set<int> &rest) {
        if (cur.size() == nums.size()) {
            int score = cur_score + abs(cur.back() - nums[cur.front()]);
            if (score < best) {
                best = score;
                ans = cur;
            } else if (score == best && cur < ans) {
                ans = cur;
            }
            return;
        }
        if (cur.size() == 0) {
            cur.push_back(0);
            rest.erase(0);
            dfs(nums, cur, cur_score, rest);
            return;
        }

        vector<int> cand;
        for (auto &&i : rest) cand.push_back(i);
        sort(cand.begin(), cand.end(), [&](int a, int b) {
            return abs(cur.back() - nums[a]) < abs(cur.back() - nums[b]);
        });
        for (auto nxt : cand) {
            cur_score += abs(cur.back() - nums[nxt]);
            if (cur_score <= best) {
                cur.push_back(nxt);
                rest.erase(nxt);
                dfs(nums, cur, cur_score, rest);
                rest.insert(nxt);
                cur.pop_back();
            }
            cur_score -= abs(cur.back() - nums[nxt]);
        }
    }

public:
    vector<int> findPermutation(vector<int> &nums) {
        vector<int> cur;
        set<int> rest;
        for (int i = 0; i < nums.size(); i++) rest.insert(i);
        dfs(nums, cur, 0, rest);
        return ans;
    }
};

void solve() {
    INT(N);
    VI(A, N);
    Solution sol;
    auto ans = sol.findPermutation(A);
    print(ans);
}
