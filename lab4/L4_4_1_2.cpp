/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
    bool dfs(TreeNode* node, long long mn, long long mx)
    {
        if (node==nullptr)
        {
            return true;
        }
        if (node->val<=mn || node->val>=mx)
        {
            return false;
        }
        return dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx);
    }
};
