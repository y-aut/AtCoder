#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        bool to_left = false;
        stack<TreeNode *> cur, nxt;
        cur.push(root);
        while (!cur.empty()) {
            ans.push_back(vector<int>());
            while (!cur.empty()) {
                auto node = cur.top();
                cur.pop();
                ans.back().push_back(node->val);
                if (!to_left) {
                    if (node->left != nullptr) nxt.push(node->left);
                    if (node->right != nullptr) nxt.push(node->right);
                } else {
                    if (node->right != nullptr) nxt.push(node->right);
                    if (node->left != nullptr) nxt.push(node->left);
                }
            }
            to_left ^= 1;
            cur = move(nxt);
            nxt = stack<TreeNode *>();
        }
        return ans;
    }
};

/*
    BFS
    stack for every depth <- TreeNode*
*/

void solve() {
    Solution sol;
}
