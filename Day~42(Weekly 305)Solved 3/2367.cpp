class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int> mp;
        int index = 1;
        for(auto i:nums){
            mp[i] = index++;
        }
        int ans = 0;
        for(auto i:nums){
            if(mp[i-diff] && mp[i+diff])
                ans++;
        }
        return ans;
    }
};