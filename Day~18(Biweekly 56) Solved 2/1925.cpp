class Solution {
public:
    int countTriples(int n) {
        vector <int> dp(251,0);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1];
            for(int j=1;j*j<i*i;j++){
                int k = sqrt(i*i-j*j);
                if(i*i == (j*j+k*k))
                    dp[i]++;
            }
        }
        return dp[n];
    }
};