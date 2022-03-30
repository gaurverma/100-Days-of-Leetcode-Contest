class Solution {
public:
    
    int calc(vector <int> nums, int den){
        int ans  = 0;
        for(auto num:nums)
            ans += ceil((double)num/den);
        return ans;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1,end = 1000007;
        int mid;
        while(start<end){
            int mid = end-(end-start)/2;
            if(calc(nums,mid)>threshold)
               start = mid+1;
            else
               end  = mid-1;
        }
        
        if(start && calc(nums,start)<=threshold) return start;
        return start+1;
        
    }
};