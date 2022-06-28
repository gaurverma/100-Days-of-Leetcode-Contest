class Solution {
public:
    typedef pair<pair<int,int>,int> ppi;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int m  = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==1){
                    for(int k=0;k<n;k++)
                        dp[i][j] = min(dp[i][j],grid[i][j]+grid[i-1][k]+moveCost[grid[i-1][k]][j]);
                    if(i==m-1)
                        ans = min(ans,dp[i][j]);
                }
                else{
                    for(int k=0;k<n;k++)
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+grid[i][j]+moveCost[grid[i-1][k]][j]);
                    if(i==m-1)
                        ans  = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};