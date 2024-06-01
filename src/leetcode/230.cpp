#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

using TreeNode = BinaryTreeNode;

class Solution {
    int dfs(TreeNode *root, int k, TreeNode **ans) {
        int size = 1;
        if (root->left != nullptr) {
            size += dfs(root->left, k, ans);
        } else if (k == 0) {
            *ans = root;
            return 0;
        }
        if (*ans != nullptr) return 0;
        if (size == k + 1) {
            *ans = root;
            return 0;
        }
        if (root->right != nullptr) {
            size += dfs(root->right, k - size, ans);
        }
        return size;
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        k--;
        TreeNode *ans = nullptr;
        dfs(root, k, &ans);
        return ans->val;
    }
};

void solve() {
    Solution sol;
    LBT(a);
    INT(k);
    print(sol.kthSmallest(a, k));
}
