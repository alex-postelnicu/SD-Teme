#include <bits/stdc++.h>
using namespace std;
int n,i,k,x;
deque<int>dq;
vector<int>v;
int main()
{
    cin>>n>>k;
    for (i=1; i<=n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for (i=0; i<n; i++)
    {
        while (!dq.empty() && v[dq.back()]>=v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.front()==i-k)
        {
            dq.pop_front();
        }
        if (i>=k-1)
        {
            cout<<v[dq.front()]<<" ";
        }
    }
}
