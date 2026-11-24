class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector <int> freq(3,0);

        for(int i=0;i<nums.size();i++)
        freq[nums[i]]++;

        int i=0;
        
        for(int j=0;j<freq.size();j++)
        {
            while(freq[j]--)
            {
                nums[i++]=j;
            }
        }
    }

};