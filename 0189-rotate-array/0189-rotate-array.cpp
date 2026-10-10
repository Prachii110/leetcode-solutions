class Solution {
public:

    void reverse(vector<int> &nums,int s,int e)
    {
        int i=s,j=e;

        while(i<j){
            swap(nums[i],nums[j]);
            i++;j--;
        }

    }

    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);

        reverse(nums,0,nums.size()-1);
    }
};