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
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        unordered_map<string, pair<int, int>> words_index;
        for (auto &&w : words) {
            auto itr = words_index.find(w);
            if (itr == words_index.end()) {
                words_index[w] = {words_index.size(), 1};
            } else {
                itr->second.second++;
            }
        }
        int word_size = words.front().size();
        for (int i = 0; i < word_size; i++) {
            vector<int> cur(words_index.size());
            int correct_count = 0;
            for (int j = i; j + word_size <= s.size(); j += word_size) {
                auto itr = words_index.find(s.substr(j, word_size));
                if (itr != words_index.end()) {
                    if (cur[itr->second.first] == itr->second.second) {
                        correct_count--;
                    }
                    if (++cur[itr->second.first] == itr->second.second) {
                        correct_count++;
                    }
                }
                if (j >= word_size * words.size()) {
                    itr = words_index.find(s.substr(j - word_size * words.size(), word_size));
                    if (itr != words_index.end()) {
                        if (cur[itr->second.first] == itr->second.second) {
                            correct_count--;
                        }
                        if (--cur[itr->second.first] == itr->second.second) {
                            correct_count++;
                        }
                    }
                }
                if (correct_count == words_index.size()) {
                    ans.push_back(j - word_size * words.size() + word_size);
                }
            }
        }
        return ans;
    }
};

/*
    words = ["ab", "cd", "ef"]
    S = "abcdefcdab"
*/

void solve() {
    Solution sol;
    STR(S);
    INT(C);
    VS(W, C);
    print(sol.findSubstring(S, W));
}
