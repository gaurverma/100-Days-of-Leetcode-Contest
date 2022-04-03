class Solution {
public:
    typedef long long LL;
    
    
    bool isvalid(vector <int>& candies, long long val,long long k){
        LL ans  = 0;
        for(auto i:candies){
            ans += i/val;
        }
        return ans>=k;
    }
    
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i:candies)
            sum +=i;
        if(sum<k) return 0;
        LL start = 1, end = *max_element(candies.begin(),candies.end());
        LL ans;
        while(start<=end){
            LL mid  = end - (end-start)/2;
            if(isvalid(candies,mid,k)){
                
                ans = mid;
                start = mid+1;
            }else
                end = mid-1;
        }
        return ans;
    }
};