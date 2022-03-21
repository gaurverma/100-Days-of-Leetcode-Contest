class Solution {
public:
    int ans  = INT_MAX;
    int minAreaRect(vector<vector<int>>& points) {
        map <int,set<int>> mp;
        for(auto point:points)
            mp[point[0]].insert(point[1]);
        for(auto i = mp.begin();i!=mp.end();i++){
           int x1 = i->first;
           for(auto j = next(i);j!=mp.end();j++){
               int x2 = j->first;
               for(auto itr = mp[x1].begin();itr!=mp[x1].end();itr++){
                   int y1 = *itr;
                   if(mp[x2].find(y1)!=mp[x2].end()){
                       for(auto itr2 = next(itr);itr2!=mp[x1].end();itr2++){
                           int y2 = *itr2;
                           if(mp[x2].find(y2)!=mp[x2].end()){
                               ans = min(ans,(x2-x1)*(y2-y1));
                               break;
                           }
                       }
                   }
               }
           }
            
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};