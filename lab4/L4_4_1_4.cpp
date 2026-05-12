/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        dfs(root, s);
        return s;
    }

    void dfs(TreeNode* root, string& s)
    {
        if (root==nullptr)
        {
            return;
        }
        s=s+to_string(root->val)+" ";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string v="";
        vector<int>valori;
        for (char c : data)
        {
            if (c==' ')
            {
                valori.push_back(stoi(v));
                v="";
            }
            else
            {
                v+=c;
            }
        }
        int i=0;
        return reconstruire(valori, i, INT_MIN, INT_MAX);
    }

    TreeNode* reconstruire(vector<int>& valori, int& i, int mn, int mx)
    {
        if (i>=valori.size())
        {
            return nullptr;
        }
        if (valori[i]<mn || valori[i]>mx)
        {
            return nullptr;
        }
        i++;
        TreeNode* root=new TreeNode(valori[i-1]);
        root->left=reconstruire(valori, i, mn, valori[i-1]);
        root->right=reconstruire(valori, i, valori[i-1], mx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
