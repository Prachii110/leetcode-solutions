class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int zero=0,one=0,diff,res=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            zero++;
            else
            one++;

            diff=zero-one;

            if(diff==0)
            {
                res=max(res,i+1);
            }
            else{
            if(mp.contains(diff))
            {
                res=max(res,i-mp[diff]);
            }
            else
            mp[diff]=i;

            }

        }

        return res;
    }
};