class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<vector<long>> dp(s.size()+1,vector<long>(s.size()+1,0));
        int ans = 1;
        for(int l=0;l<s.size();l++){
            long  mn;
            if(l!=0)
                mn = dp[l-1][s.size()-l];
            for(int j=s.size()-l-1;j>=0;j--){
                if(l==0){
                    dp[l][j] = s[j]-'0';
                }
                else{
                    if(s[j]=='0')
                        dp[l][j] = mn;
                    else{
                        if(l>=34)
                            dp[l][j] = INT_MAX;
                        else
                            dp[l][j] += mn+pow(2,l);
                    }
                    mn  = min(mn,dp[l-1][j]);
                    if(dp[l][j]<=k)
                        ans  = l+1;
                    if(dp[l][j]>=INT_MAX)
                        dp[l][j] = INT_MAX;
                }
            }
        }
        

        return ans;
    }
};