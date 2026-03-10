#include <bits/stdc++.h>
using namespace std;
int n,l,r,m,ans;
int main()
{
    cin>>n;
    l=1;
    r=n;
    while (l<=r)
    {
        m=(l+r)/2;
        if (m*m<=n)
        {
            ans=m;
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    cout<<ans;
}
