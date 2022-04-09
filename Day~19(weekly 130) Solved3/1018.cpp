class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int val = 0;
        for(auto num:nums){
            val *= 2;
            if(num==1) val++;
            val = val%10;
            if(val==0 || val==5)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};