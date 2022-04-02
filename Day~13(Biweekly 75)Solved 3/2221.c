class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector <int> num;
        for(int i=1;i<nums.size();i++)
            num.push_back((nums[i-1]+nums[i])%10);
        return triangularSum(num);
    }
};