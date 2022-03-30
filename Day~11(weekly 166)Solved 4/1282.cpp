class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gS) {
        vector <vector<int>> ans;
        unordered_map <int,vector<int>> mp;
        for(int i=0;i<gS.size();i++){
            int val  = gS[i];
            mp[val].push_back(i);
            if(mp[val].size()==val){
                ans.push_back(mp[val]);
                mp.erase(val);
            }
        }
        return ans;
    }
};