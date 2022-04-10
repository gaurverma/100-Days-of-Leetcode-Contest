class Solution {
public:
    int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> p;
        for(auto num:nums)
            p.push(num);
        while(k){
            int a = p.top();
            p.pop();
            a++;
            p.push(a);
            k--;
        }
        long long ans = 1;
        while(!p.empty()){
            ans = (((ans)%mod)*(p.top()%mod)%mod);
            p.pop();
        }
        return ans;
    }
};