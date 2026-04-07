#include <bits/stdc++.h>
using namespace std;
class hash_table
{
private:
    vector<list<int>>v;
    int nr,capacity;
    int hash_(int x)
    {
        int h=x&capacity;
        if (h<0)
        {
            h+=capacity;
        }
        return h;
    }
    void resize_()
    {
        int aux=capacity;
        capacity*=2;
        vector<list<int>>vaux(capacity);
        for (int i=0; i<aux; i++)
        {
            for (auto it : v[i])
            {
                int j=hash_(it);
                vaux[j].push_back(it);
            }
        }
        v=vaux;
    }
public:
    hash_()
    {
        nr=0;
        capacity=1;
        v.resize(1);
    }
    void insert_(int x)
    {
        if (exists(x))
        {
            return;
        }
        else
        {
            if (nr==capacity)
            {
                resize_();
            }
            int i=hash_(x);
            v[i].push_back(x);
            nr++;
        }
    }
    void erase_(int x)
    {
        int i=hash_(x);
        auto& lista=v[i];
        for (auto it=lista.begin(); it!=lista.end(); it++)
        {
            if (*it==x)
            {
                lista.erase(it);
                nr--;
                return;
            }
        }
    }
    bool exists(int x)
    {
        int i=hash_(x);
        for (auto it : v[i])
        {
            if (it==x)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{

}
