class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums[0].length();
        for(auto q:queries){
            int trim = q[1], k =  q[0];
            priority_queue <pair<string,int>> pq;
            for(int i=0;i<nums.size();i++){
                pq.push({nums[i].substr(n-trim),i});
                if(pq.size()>k)
                    pq.pop();
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};