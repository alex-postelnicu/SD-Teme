#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,ans,dist;
vector<int>g[1005];
priority_queue<int,vector<int>,greater<int>>pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>dist;
        pq.push(dist);
    }
    while (pq.size()>1)
    {
        i=pq.top();
        pq.pop();
        j=pq.top();
        pq.pop();
        ans+=i+j;
        pq.push(i+j);
    }
    cout<<ans;
}
