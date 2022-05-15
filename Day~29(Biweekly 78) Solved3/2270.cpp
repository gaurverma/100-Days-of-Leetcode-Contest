class Solution {
public:
    int waysToSplitArray(vector<int>& n) {
        vector<long long> nums;
        for(auto i:n)
            nums.push_back(i);
        int ans = 0;
        for(int i=1;i<nums.size();i++)
            nums[i] += nums[i-1];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[nums.size()-1]-nums[i])
                ans++;
        }
        return ans;
    }
};