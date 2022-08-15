class Solution {
public:
    int longestIdealString(string s, int k) {
        unordered_map<char,int> dp;
        for(char c:s){
            int val = 0, temp = k+1;
            for(char i=c;i>='a'&& temp;i--,temp--){
                //cout<<i<<endl;
                val = max(val,dp[i]);
            }
            temp = k+1;
            for(char i=c;i<='z'&& temp;i++,temp--){
                val = max(val,dp[i]);
            }
            dp[c] = val + 1;
        }
        int ans = 0;
        for(char c='a';c<='z';c++)
            ans = max(ans,dp[c]);
        return ans;
    }
};