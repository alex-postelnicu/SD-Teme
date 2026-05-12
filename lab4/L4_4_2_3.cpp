#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,u,ans,dist[50005],val,d,v;
vector<pair<int,int>>g[50005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
    cin>>n>>m;
    for (i=2; i<=n; i++)
    {
        dist[i]=2e9;
    }
    dist[1]=0;
    for (k=1; k<=m; k++)
    {
        cin>>i>>j>>val;
        g[i].push_back({j,val});
    }
    pq.push({dist[1],1});
    while (!pq.empty())
    {
        d=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if (d>dist[u])
        {
            continue;
        }
        for (auto it : g[u])
        {
            v=it.first;
            val=it.second;
            if (dist[v]>dist[u]+val)
            {
                dist[v]=dist[u]+val;
                pq.push({dist[v],v});
            }
        }
    }
    for (i=2; i<=n; i++)
    {
        if (dist[i]==2e9)
        {
            cout<<0<<" ";
        }
        else
        {
            cout<<dist[i]<<" ";
        }
    }
}
