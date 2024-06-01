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
    bool check(const string &a, const string &b) {
        assert(a.size() == b.size());
        bool differ = false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (differ) return false;
                differ = true;
            }
        }
        return differ;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int endWordIndex = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                endWordIndex = i;
                break;
            }
        }
        if (endWordIndex == -1) return 0;

        vector<vector<int>> edges(wordList.size());
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (check(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<int> dist(wordList.size(), -1);
        for (int i = 0; i < wordList.size(); i++) {
            if (check(beginWord, wordList[i])) {
                q.push(i);
                dist[i] = 1;
            }
        }

        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (auto i : edges[v]) {
                if (dist[i] != -1) continue;
                q.push(i);
                dist[i] = dist[v] + 1;
            }
        }

        if (dist[endWordIndex] == -1) return 0;
        else return dist[endWordIndex] + 1;
    }
};

/*
    BFS
    add edges where the distance of two words is 1
*/

void solve() {
    Solution sol;
}
