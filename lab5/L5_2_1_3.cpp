#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* child[2];
    int sfarsit;
    Node()
    {
        sfarsit=0;
        for (int i=0; i<2; i++)
        {
            child[i]=nullptr;
        }
    }
};

class Trie
{
private:
    Node* root;

public:
    Trie()
    {
        root=new Node();
    }

    void insert(int val, int poz)
    {
        Node* u=root;
        for (int i=20; i>=0; i--)
        {
            int j=(val>>i)&1;
            if (u->child[j]==nullptr)
            {
                u->child[j]=new Node();
            }
            u=u->child[j];
            u->sfarsit=poz;
        }
    }

    pair<int,int>mx(int val)
    {
        Node* u=root;
        int ans=0;
        for (int i=20; i>=0; i--)
        {
            int j=(val>>i)&1;
            int k=1-j;
            if (u->child[k]!=nullptr)
            {
                ans=ans | (k<<i);
                u=u->child[k];
            }
            else
            {
                ans=ans | (j<<i);
                u=u->child[j];
            }
        }
        return {ans, u->sfarsit};
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xormax.in", "r", stdin);
    freopen("xormax.out", "w", stdout);
    int n,i,mx=-1,pref=0,x,xor_,start,stop;
    pair<int,int>p;
    Trie trie;
    trie.insert(0,0);
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>x;
        pref^=x;
        p=trie.mx(pref);
        xor_=pref^p.first;
        if (xor_>mx)
        {
            mx=xor_;
            start=p.second+1;
            stop=i;
        }
        trie.insert(pref,i);
    }
    cout<<mx<<" "<<start<<" "<<stop;
}
