class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int mx = 100005;
        vector <int> lscn(mx,0);
        vector <bool> played(mx,false);
        for(auto match:matches){
            lscn[match[1]]++;
            played[match[0]] = true;
            played[match[1]]= true;
        }
        vector <int> allwin,onelost;
        for(int i=1;i<mx;i++){
            if(played[i]){
                if(lscn[i]==0)
                    allwin.push_back(i);
                else if(lscn[i]==1)
                    onelost.push_back(i);
            }
        }
        vector <vector<int>> ans = {allwin,onelost};
        return ans;
    }
};