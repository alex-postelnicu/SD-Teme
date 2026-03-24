#include <bits/stdc++.h>
using namespace std;
int v[200005],i,n;
stack<int>st;
int main()
{
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>v[i];
    }
    for (i=0; i<n; i++)
    {
        while (!st.empty() && v[st.top()]>=v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            cout<<0<<" ";
        }
        else
        {
            cout<<st.top()+1<<" ";
        }
        st.push(i);
    }
}
