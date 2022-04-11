class Solution {
public:
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr = 0;
        for(auto num:nums)
            xr ^= num;
        vector <int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            unsigned int res = ~xr;
            res <<= (32-maximumBit);
            res >>= (32-maximumBit);
            xr ^= nums[i];
            ans.push_back(res);
        }
        return ans;
    }
};