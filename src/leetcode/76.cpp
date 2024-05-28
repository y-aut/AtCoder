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
    string minWindow(string s, string t) {
        int size = 1e8, start = 0;
        int p1 = 0, p2 = 0;
        unordered_map<char, int> tchars, cur;
        int cur_count = 0;
        for (char c : t) tchars[c]++;
        while (p2 <= s.size()) {
            if (cur_count == t.size()) {
                if (cur.count(s[p1])) {
                    if (--cur[s[p1]] < tchars[s[p1]]) {
                        cur_count--;
                    }
                }
                p1++;
            } else {
                if (p2 == s.size()) break;
                if (tchars.count(s[p2])) {
                    if (cur[s[p2]]++ < tchars[s[p2]]) {
                        cur_count++;
                    }
                }
                p2++;
            }
            if (cur_count == t.size()) {
                if (p2 - p1 < size) {
                    size = p2 - p1;
                    start = p1;
                }
            }
        }
        if (size == 1e8) return "";
        return s.substr(start, size);
    }
};

void solve() {
    Solution sol;
    STR(S, T);
    print(sol.minWindow(S, T));
}
