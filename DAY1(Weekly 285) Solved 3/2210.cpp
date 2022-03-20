class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0 ;
        for(int i=1;i<nums.size()-1;i++){
            bool  ngl = false,ngr = false,nsl = false,nsr = false;
            if(nums[i]==nums[i-1])
                continue;
            for(int j=i-1;j>=0;j--){
                if(nums[i]==nums[j])
                    continue;
                if(nums[j]<nums[i])
                    nsl = true;
                else if(nums[j]>nums[i])
                    ngl = true;
                break;
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    continue;
                if(nums[j]<nums[i])
                    nsr = true;
                else if(nums[j]>nums[i])
                    ngr = true;
                break;
            }
            if((nsr && nsl)||(ngl && ngr)){
                ans++;
            } 
        }
        return ans;
    }
};