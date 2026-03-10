#include <bits/stdc++.h>
using namespace std;
int n,s,i,j,a[1001],mn,poz1,poz2;
int main()
{
    cin>>n>>s;
    mn=INT_MAX;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    i=1;
    j=n;
    while (i<j)
    {
        int dif=abs(a[i]+a[j]-s);
        if (dif<mn)
        {
            mn=dif;
            poz1=i;
            poz2=j;
        }
        if (a[i]+a[j]<s)
            i++;
        else
            j--;
    }
    cout<<poz1<<" "<<poz2;
}
