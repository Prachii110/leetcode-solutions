class Solution {
public:
    int hIndex(vector<int>& citations) {
        map<int,int>mp;
        int count=0,val,ans=0;

        for(int i=0;i<citations.size();i++)
        {
            if(citations[i] > citations.size())
            mp[citations.size()]++;
            else
            mp[citations[i]]++;
        }

        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            count+=it->second;

            ans = max(ans, min(it->first, count));
            if(it->first<=count)
            return ans;
        }

        return ans;
    }
};