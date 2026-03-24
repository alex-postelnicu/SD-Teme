#include <bits/stdc++.h>
using namespace std;
int n,i,v[200005],h,w,mx,a;
stack<int>st;
int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    for (i=1; i<=n; i++)
    {
        while (!st.empty() && v[st.top()]>v[i])
        {
            h=v[st.top()];
            st.pop();
            if (st.empty())
            {
                w=i-1;
            }
            else
            {
                w=i-st.top()-1;
            }
            a=h*w;
            mx=max(mx,a);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        h=v[st.top()];
        st.pop();
        if (st.empty())
        {
            w=n;
        }
        else
        {
            w=n-st.top();
        }
        a=h*w;
        mx=max(mx,a);
    }
    cout<<mx;
}
