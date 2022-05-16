class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map <int,int> mp;
        int ans  = INT_MAX;
        int i = 0;
        for(auto card:cards){
            if(mp.find(card)!=mp.end())
              ans  = min(ans,i-mp[card]+1);
            mp[card] = i++;
        }
        return ans==INT_MAX?-1:ans;
    }
};