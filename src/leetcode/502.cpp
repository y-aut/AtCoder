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
    struct Project {
        int capital;
        int profit;

        Project() {}
        Project(int _cap, int _pro) : capital(_cap), profit(_pro) {}
    };

public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        vector<Project> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
            return a.capital < b.capital;
        });
        auto comp = [](const Project &a, const Project &b) {
            return a.profit < b.profit;
        };
        priority_queue<Project, vector<Project>, decltype(comp)> p(comp);
        int pushed = 0;
        for (; pushed < projects.size(); pushed++) {
            if (projects[pushed].capital > w) break;
            p.push(projects[pushed]);
        }
        k = min(k, (int)projects.size());
        for (int i = 0; i < k; i++) {
            if (p.empty()) break;
            auto pr = p.top();
            p.pop();
            w += pr.profit;
            for (; pushed < projects.size(); pushed++) {
                if (projects[pushed].capital > w) break;
                p.push(projects[pushed]);
            }
        }
        return w;
    }
};

/*
    sort the projects by its capital value
    dp[i][j]: the maximum capital when we've seen i projects so far, and done j projects
    dp[i+1][j+1] <- dp[i][j] + projects[i].profit (if dp[i][j] >= projects[i].capital)
    dp[i+1][j] <- dp[i][j]

    dp[i][j]: the maximum capital when we've seen i projects so far, and done less than or equal to j projects

    dif[j] := dp[j] - dp[j-1] (dp[-1] == 0)
    dp[j] = sum[k=0...j] dif[j]
    dp[j+1] <- max(dp[j+1], dp[j] + projects[i].profit)
    dif[j] <- max(dif[j], projects[i].profit) (if dp[j] >= projects[i].capital)
*/

void solve() {
    Solution sol;
    INT(k, w);
    LVI(a);
    LVI(b);
    print(sol.findMaximizedCapital(k, w, a, b));
}
