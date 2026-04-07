#include <bits/stdc++.h>
using namespace std;
int n,l,u,i,st,dr,ans,nr1,nr2;
unordered_map<int,int>frecv;
int main()
{
    cin>>n>>l>>u;
    vector<int>v(n+1);
    for (i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    st=1;
    for (dr=1; dr<=n; dr++)
    {
        frecv[v[dr]]++;
        while (frecv.size()>u)
        {
            frecv[v[st]]--;
            if (!frecv[v[st]])
            {
                frecv.erase(v[st]);
            }
            st++;
        }
        nr1+=dr-st+1;
    }
    frecv.clear();
    st=1;
    for (dr=1; dr<=n; dr++)
    {
        frecv[v[dr]]++;
        while (frecv.size()>l-1)
        {
            frecv[v[st]]--;
            if (!frecv[v[st]])
            {
                frecv.erase(v[st]);
            }
            st++;
        }
        nr2+=dr-st+1;
    }
    ans=nr1-nr2;
    cout<<ans;
}
