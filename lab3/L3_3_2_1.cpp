#include <bits/stdc++.h>
using namespace std;
int n,s,i,j,k;
unordered_map<int,int>m;
int main()
{
    cin>>n>>s;
    vector<int>v(n+1);
    for (i=1; i<=n; i++)
    {
        cin>>v[i];
        m[v[i]]=i;
    }
    for (i=1; i<=n-2; i++)
    {
        for (j=i+1; j<=n-1; j++)
        {
            k=s-v[i]-v[j];
            if (m[k]>j)
            {
                cout<<i<<" "<<j<<" "<<m[k];
                break;
            }
        }
    }
}
