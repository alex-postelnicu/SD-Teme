#include <bits/stdc++.h>
using namespace std;
int g[1001][1001],i,j,x,y,a,b,n,m,di[4]={1,0,-1,0},dj[4]={0,1,0,-1},k,iv,jv;
queue<pair<int,int>>q;
int main()
{
    cin>>n>>m;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            cin>>g[i][j];
            ///normal cells = 0
            ///blocked cells = -1
        }
    }
    cin>>x>>y>>a>>b;
    g[x][y]=1;
    q.push({x,y});
    while (!q.empty())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        if (i==a && j==b)
            break;
        else
        {
            for (k=0; k<4; k++)
            {
                iv=i+di[k];
                jv=j+dj[k];
                if (iv>=1 && iv<=n && jv>=1 && jv<=m && g[iv][jv]==0 && g[iv][jv]!=-1)
                {
                    g[iv][jv]=g[i][j]+1;
                    q.push({iv,jv});
                }
            }
        }
    }
    if (g[a][b]==-1)
        cout<<-1;
    else
        cout<<g[a][b]-1;
}
