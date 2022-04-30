class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector <long long> num;
        for(int i=0;i<nums.size();i++)
            num.push_back(nums[i]);
        int n = num.size();
        for(int i=1;i<num.size();i++){
            num[i] += num[i-1];
        }
        int ans  = 0;
        int mnval = INT_MAX;
        for(int i=0;i<num.size();i++){
            int lavg = num[i]/(i+1);
            int ravg = i!=(n-1)?(num[num.size()-1]-num[i])/(n-i-1):0;
            if(abs(lavg-ravg)<mnval){
                ans = i;
                mnval = abs(lavg-ravg);
            }
               
        }
        return ans;
    }
};