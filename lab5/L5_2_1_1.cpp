#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* child[26];
    int nr, sfarsit;
    Node()
    {
        nr=0;
        sfarsit=0;
        for (int i=0; i<26; i++)
        {
            child[i]=nullptr;
        }
    }
};

class Trie
{
private:
    Node* root;

    void dfs(Node* u, string& s, int level)
    {
        if (u!=root)
        {
            u->nr--;
        }
        if (level==s.size())
        {
            u->sfarsit--;
            return;
        }
        int j=s[level]-'a';
        dfs(u->child[j], s, level+1);
        if (u->child[j]->nr==0)
        {
            delete u->child[j];
            u->child[j]=nullptr;
        }
    }

public:
    Trie()
    {
        root=new Node();
    }

    void insert(string& s)
    {
        Node* u=root;
        for (int i=0; i<s.size(); i++)
        {
            int j=s[i]-'a';
            if (u->child[j]==nullptr)
            {
                u->child[j]=new Node();
            }
            u=u->child[j];
            u->nr++;
        }
        u->sfarsit++;
    }

    void erase(string& s)
    {
        dfs(root,s,0);
    }

    int longest_prefix(string& s)
    {
        Node* u=root;
        int ans=0;
        for (int i=0; i<s.size(); i++)
        {
            int j=s[i]-'a';
            if (u->child[j]==nullptr)
            {
                break;
            }
            u=u->child[j];
            ans++;
        }
        return ans;
    }

    int count(string& s)
    {
        Node* u=root;
        for (int i=0; i<s.size(); i++)
        {
            int j=s[i]-'a';
            if (u->child[j]==nullptr)
            {
                return 0;
            }
            u=u->child[j];
        }
        return u->sfarsit;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("trie.in", "r", stdin);
    freopen("trie.out", "w", stdout);
    int op;
    string s;
    Trie trie;
    while (cin>>op>>s)
    {
        if (op==0)
        {
            trie.insert(s);
        }
        else if (op==1)
        {
            trie.erase(s);
        }
        else if (op==2)
        {
            cout<<trie.count(s)<<"\n";
        }
        else
        {
            cout<<trie.longest_prefix(s)<<"\n";
        }
    }
}
