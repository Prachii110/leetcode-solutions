class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st; // because the lookup complexity is constant in this DS
        int length=0,max_len=0,val;

        //inserting all the values in the set
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }

        for(int num : st)
        {
            if(!st.contains(num-1))
            {
                length=0;
                val=num;
                while(st.contains(val))
                {
                    length++;
                    max_len=max(max_len,length);
                    val++;
                }
            }
        }

        return max_len;

    }
};