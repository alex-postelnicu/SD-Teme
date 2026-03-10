#include <bits/stdc++.h>
using namespace std;
int n,i,a[1001],l,r,q;
int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>q;
    while (q--)
    {
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<" ";
    }
}
