class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = 0, e = nums.size()-1;
        int ans = 0;
        while(s<e){
            ans = max(ans,nums[s++]+nums[e--]);
        }
        return ans;
    }
};