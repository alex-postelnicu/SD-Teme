#include <bits/stdc++.h>
using namespace std;
class rand_choice
{
private:
    vector<int>v;
public:
    void insert(int x)
    {
        v.push_back(x);
    }
    void pop()
    {
        if (!v.empty())
        {
            int i=rand()%v.size();
            cout<<v[i];
            swap(v[i],v[v.size()-1]);
            v.pop_back();
        }
    }
};
