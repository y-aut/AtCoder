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
    unordered_map<TreeNode *, int> memo;
    unordered_map<TreeNode *, int> memo2;
    int calc(TreeNode *node) {
        if (memo.count(node)) return memo[node];
        int left = 0, right = 0;
        if (node->left != nullptr) {
            left = max(left, calc(node->left));
        }
        if (node->right != nullptr) {
            right = max(right, calc(node->right));
        }
        memo2[node] = left + right + node->val;
        return memo[node] = max(left, right) + node->val;
    }

public:
    int maxPathSum(TreeNode *root) {
        calc(root);
        int ans = -1e8;
        for (auto &&i : memo2) ans = max(ans, i.second);
        return ans;
    }
};

void solve() {
    Solution sol;
}
