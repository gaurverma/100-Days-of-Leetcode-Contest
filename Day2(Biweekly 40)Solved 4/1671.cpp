class Solution {
public:
    
    vector <int> LIS(vector<int> num){
        vector <int> dp(num.size(),0);
        for(int i=0;i<num.size();i++){
            for(int j=i-1;j>=0;j--){
                if(num[j]<num[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        vector <int> Is = LIS(nums);
        
        reverse(nums.begin(),nums.end());
        vector <int> Ds = LIS(nums);
        reverse(Ds.begin(),Ds.end());
        
        reverse(nums.begin(),nums.end());
       
        
        int ans = INT_MAX;
        
        for(int i=1;i<nums.size()-1;i++){
            int nel = i;
            int ner = nums.size()-i-1;
            if(Is[i]==0 || Ds[i]==0)
                continue;
            int netoberemoved = (nel-Is[i])+(ner-Ds[i]);
            ans  = min(ans,netoberemoved);
        }
        
        return ans;
    }
};