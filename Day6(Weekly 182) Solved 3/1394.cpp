class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map <int,int> mp;
        int ans  = -1;
        for(auto num:arr)
            mp[num]++;
        for(auto pair:mp){
            if(pair.first==pair.second && pair.first>ans)
                ans  = pair.first;
        }
        return ans;
    }
};