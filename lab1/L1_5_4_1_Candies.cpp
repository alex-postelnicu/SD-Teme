class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mx=candies[0],i,l,r,ans,m;
        long long s;
        for (i=1; i<candies.size(); i++)
        {
            mx=max(candies[i],mx);
        }
        l=1;
        r=mx;
        while (l<=r)
        {
            m=l+(r-l)/2;
            s=0;
            for (i=0; i<candies.size(); i++)
            {
                s+=candies[i]/m;
            }
            if (s>=k)
            {
                ans=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return ans;
    }
};
