class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int ans = 0;
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            sum2 += nums2[i];
            if(sum2-sum1>0)
                ans = max(ans,sum2-sum1);
            else{
                sum1 = 0;
                sum2 = 0;
            }
        }
        res = accumulate(nums1.begin(),nums1.end(),0)+ans;
        ans = 0;
        sum1 = 0, sum2 = 0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            sum2 += nums2[i];
            if(sum1-sum2>0)
                ans = max(ans,sum1-sum2);
            else{
                sum1 = 0;
                sum2 = 0;
            }
        }
        int val = accumulate(nums2.begin(),nums2.end(),0)+ans;
        res = max(res,val);
        return res;
    }
    
};