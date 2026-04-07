#include <bits/stdc++.h>
using namespace std;
int n,i,j,st,dr,l,ans,m;
string s,t;
unordered_set<string>s1;
unordered_set<string>s2;
bool ok=true;
int main()
{
    cin>>n;
    vector<string>v(n+1);
    size_t mn=INT_MAX;
    for (i=1; i<=n; i++)
    {
        cin>>v[i];
        mn=min(mn,v[i].size());
    }
    st=1;
    dr=mn;
    while (st<=dr)
    {
        m=(st+dr)/2;
        ok=true;
        s1.clear();
        for (i=0; i<v[1].size()-m+1; i++)
        {
            s1.insert(v[1].substr(i,m));
        }
        for (i=2; i<=n; i++)
        {
            s2.clear();
            for (j=0; j<v[i].size()-m+1; j++)
            {
                t=v[i].substr(j,m);
                s2.insert(t);
            }
            unordered_set<string>s3=s1;
            for (auto it : s3)
            {
                if (!s2.count(it))
                {
                    s1.erase(it);
                }
            }
            if (s1.empty())
            {
                ok=false;
                dr=m-1;
                break;
            }
        }
        if (ok)
        {
            ans=m;
            st=m+1;
        }
    }
    cout<<ans;
}
