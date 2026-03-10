#include <bits/stdc++.h>
using namespace std;
int n,i,k,a[1001],mx;
int main()
{
    cin>>n>>k;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    vector<int>frecv(mx+1,0);
    for (i=1; i<=n; i++)
    {
        frecv[a[i]]++;
    }
    for (i=0; i<=mx; i++)
    {
        k-=frecv[i];
        if (k<=0)
        {
            cout<<i;
            break;
        }
    }
}
