#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],i,j,n,m,x,poz1,poz2;
int main()
{
    cin>>n>>m>>x;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    i=1;
    j=n;
    int ok=0;
    while (i<=n && j>=1)
    {
        if (a[i][j]==x)
        {
            ok=1;
            poz1=i;
            poz2=j;
            break;
        }
        else if (a[i][j]<x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if (ok==0)
    {
        cout<<x<<" nu exista\n";
    }
    else
    {
        cout<<poz1<<" "<<poz2;
    }
}
