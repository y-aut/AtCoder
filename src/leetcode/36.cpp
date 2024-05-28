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
    bool isValidSudoku(vector<vector<char>> &board) {
        bool ok = true;
        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (s.count(board[i][j])) {
                    ok = false;
                    break;
                }
                s.insert(board[i][j]);
            }
        }
        for (int j = 0; j < 9; j++) {
            unordered_set<char> s;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (s.count(board[i][j])) {
                    ok = false;
                    break;
                }
                s.insert(board[i][j]);
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> s;
                for (int i2 = 0; i2 < 3; i2++) {
                    for (int j2 = 0; j2 < 3; j2++) {
                        if (board[i + i2][j + j2] == '.') continue;
                        if (s.count(board[i + i2][j + j2])) {
                            ok = false;
                            break;
                        }
                        s.insert(board[i + i2][j + j2]);
                    }
                }
            }
        }
        return ok;
    }
};

void solve() {
    Solution sol;
}
