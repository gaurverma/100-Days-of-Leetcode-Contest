class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map <int,priority_queue<int>> mp;
        int ans = -1;
        for(auto i:nums){
            int sum = 0,t = i;
            while(i){
                sum += i%10;
                i = i/10;
            }
            mp[sum].push(t);
        }
        for(auto &i:mp){
            if(i.second.size()>=2){
                int a  = i.second.top();
                i.second.pop();
                int b = i.second.top();
                ans = max(ans,a+b);
            }
        }
        return ans;
    }
};