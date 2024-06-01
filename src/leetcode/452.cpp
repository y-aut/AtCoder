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
    int findMinArrowShots(vector<vector<int>> &points) {
        vector<int> xs;
        for (auto &&i : points) xs.push_back(i[0]), xs.push_back(i[1]);
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        unordered_map<int, int> xm;
        for (int i = 0; i < xs.size(); i++) xm[xs[i]] = i;
        vector<vector<int>> xstarts(xm.size()), xends(xm.size());
        for (int i = 0; i < points.size(); i++) {
            xstarts[xm[points[i][0]]].push_back(i);
            xends[xm[points[i][1]]].push_back(i);
        }
        int ans = 0;
        vector<int> targets;
        vector<bool> shot(points.size());
        for (int i = 0; i < xm.size(); i++) {
            for (int j : xstarts[i]) targets.push_back(j);
            for (int j : xends[i]) {
                if (!shot[j]) {
                    for (int k : targets) shot[k] = true;
                    targets.clear();
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
    greedy method

    ( [      ]    {    )    (   }    )
    sort by x_end
*/

void solve() {
    Solution sol;
    LVVI(a);
    print(sol.findMinArrowShots(a));
}
