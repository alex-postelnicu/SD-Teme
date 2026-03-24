class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        char c;
        int nr;
        string ans="";
        for (int i=0; i<s.size(); i++)
        {
            if (st.empty())
            {
                st.push({s[i],1});
            }
            else
            {
                c=st.top().first;
                nr=st.top().second;
                if (s[i]==c)
                {
                    st.pop();
                    st.push({c,nr+1});
                    nr++;
                }
                else
                {
                    st.push({s[i],1});
                }
                while (!st.empty() && st.top().second>=k)
                {
                    c=st.top().first;
                    nr=st.top().second;
                    st.pop();
                    nr-=k;
                    if (nr>0)
                    {
                        st.push({c,nr});
                    }
                }
            }
        }
        while (!st.empty())
        {
            c=st.top().first;
            nr=st.top().second;
            st.pop();
            while (nr--)
            {
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
