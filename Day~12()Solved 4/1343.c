class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int minSum = k*threshold;
        int ans  = 0;
        int sum = 0;
        for(int  i=0;i<k;i++)
            sum += arr[i];
        if(sum>=minSum)
            ans++;
        for(int i=k;i<arr.size();i++){
            sum += arr[i];
            sum -= arr[i-k];
            if(sum>=minSum)
                ans++;
        }
        return ans;
    }
};