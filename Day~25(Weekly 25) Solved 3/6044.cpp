class Solution {
public:

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector <int> ans;
        unordered_map <int,int> psum;
        for(auto flower:flowers){
            psum[flower[0]] += 1,
            psum[flower[1]+1] += -1;
        }
        vector <pair<int,int>> vec;
        for(auto p:psum){
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<vec.size();i++){
            vec[i].second += vec[i-1].second;
        }
        for(auto p:persons){
            int start = 0, end = vec.size()-1;
            int pans = 0;
            while(start<=end){
                int mid = end-(end-start)/2;
                if(vec[mid].first<=p){
                    pans = vec[mid].second;
                    start = mid+1;
                }else
                    end = mid-1;
            }
            ans.push_back(pans);
        }
           
        return ans;
    }
};