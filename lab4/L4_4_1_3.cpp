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
    TreeNode* ans1;
    TreeNode* ans2;
    TreeNode* prev;
    void recoverTree(TreeNode* root) {
        dfs(root);
        std::swap(ans1->val,ans2->val);
    }
    void dfs(TreeNode* root)
    {
        if (root==nullptr)
        {
            return;
        }
        dfs(root->left);
        if (ans1==nullptr && (prev==nullptr || prev->val>=root->val))
        {
            ans1=prev;
        }
        if (ans1!=nullptr && prev->val>=root->val)
        {
            ans2=root;
        }
        prev=root;
        dfs(root->right);
    }
};
