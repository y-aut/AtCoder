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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode *> cur;
        cur.push(root);
        while (!cur.empty()) {
            queue<TreeNode *> nxt;
            while (!cur.empty()) {
                auto node = cur.front();
                cur.pop();
                if (cur.empty()) ans.push_back(node->val);
                if (node->left != nullptr) nxt.push(node->left);
                if (node->right != nullptr) nxt.push(node->right);
            }
            cur = move(nxt);
        }
        return ans;
    }
};

void solve() {
    Solution sol;
}
