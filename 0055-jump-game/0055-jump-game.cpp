class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1;
        int ans=0;

        for(int i=0;i<=last;i++)
        {
            if(i>ans)
            return false;

            ans=max(ans,i+nums[i]);

            if(ans>=last)
            return true;

        }

        return false;
    }
       
};