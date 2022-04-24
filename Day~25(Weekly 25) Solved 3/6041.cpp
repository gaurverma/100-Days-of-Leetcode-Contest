class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map <int,int> mp;
        for(auto num:nums){
            for(auto i:num)
                mp[i]++;
        }
        vector <int> ans;
        for(auto i:mp)
            if(i.second==nums.size())
            ans.push_back(i.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
};