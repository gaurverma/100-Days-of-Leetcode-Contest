class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minval = INT_MAX;
        int  prefsum = 0;
        for(auto num : nums){
            prefsum += num;
            minval = min(minval,prefsum);
        }
        if(minval>=0) return 1;
        else return abs(minval)+1;
    }
};