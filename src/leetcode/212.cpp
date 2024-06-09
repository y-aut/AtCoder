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
    class Trie {
    public:
        struct Node {
            vector<Node *> children;
            bool exist;
            Node *parent;
            char c;

            Node() : children(26), exist(false), parent(nullptr), c(0) {}
            Node(char _c, Node *_parent) : children(26), exist(false), parent(_parent), c(_c) {}

            string retrieve() const {
                if (parent == nullptr) return "";
                auto &&s = parent->retrieve();
                s.push_back(c);
                return s;
            }
        };
        Node root;

        void insert(string word) {
            Node *cur = &root;
            for (char c : word) {
                if (cur->children[c - 'a'] == nullptr) {
                    cur->children[c - 'a'] = new Node(c, cur);
                }
                cur = cur->children[c - 'a'];
            }
            cur->exist = true;
        }
    };

    void dfs(const vector<vector<char>> &board, const Trie::Node *node, pair<int, int> cell, string &cur,
             vector<vector<bool>> &visited, unordered_set<const Trie::Node *> &ans) {
        if (node->exist) ans.insert(node);
        int DY[] = {1, 0, -1, 0};
        int DX[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int ny = cell.first + DY[i], nx = cell.second + DX[i];
            if (!(0 <= ny && ny < board.size() && 0 <= nx && nx < board[0].size())) continue;
            if (visited[ny][nx]) continue;
            char c = board[ny][nx];
            Trie::Node *new_node = node->children[c - 'a'];
            if (new_node == nullptr) continue;
            visited[ny][nx] = true;
            cur.push_back(board[ny][nx]);
            dfs(board, new_node, {ny, nx}, cur, visited, ans);
            cur.pop_back();
            visited[ny][nx] = false;
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie trie;
        for (auto &&w : words) trie.insert(w);
        string cur = "";
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        unordered_set<const Trie::Node *> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (trie.root.children[board[i][j] - 'a'] == nullptr) continue;
                visited[i][j] = true;
                cur.push_back(board[i][j]);
                dfs(board, trie.root.children[board[i][j] - 'a'], {i, j}, cur, visited, ans);
                cur.pop_back();
                visited[i][j] = false;
            }
        }
        vector<string> res;
        for (auto n : ans) res.push_back(n->retrieve());
        return res;
    }
};

/*
    dfs(board, trie, cell, cur, ans)
*/

void solve() {
    Solution sol;
    INT(N);
    VS(S, N);
    INT(K);
    VS(W, K);
    vector<vc> board;
    repi(i, S) {
        board.pb(vc());
        repi(j, i) board.back().pb(j);
    }
    print(sol.findWords(board, W));
}
