class Solution {
public:
    int m, n;
    vector <vector<unordered_map <int, bool>>> dp;
    
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n  = grid[0].size();
        dp = vector <vector<unordered_map <int, bool>>> (m,vector<unordered_map <int, bool>>(n));
        if((m+n)%2==0) return false;
        int maxopen = (m+n-1)/2;
        if(grid[0][0]==')' || grid[m-1][n-1]=='(')
            return false;
        return dfs(grid,0,0,maxopen,0);
    }
    
    bool dfs(vector<vector<char>>& grid,int i,int j, int maxopen, int open){
        if(open<0 || open>maxopen || i>=m || j>=n || dp[i][j][open])
            return false;
        if(i==m-1 && j==n-1){
            open--;
            if(open==0)
                return true;
            return false;
        }
        if(grid[i][j]=='('){
            if(dfs(grid,i+1,j,maxopen,open+1)||dfs(grid,i,j+1,maxopen,open+1))
                return true;
        }else{
             if(dfs(grid,i+1,j,maxopen,open-1)||dfs(grid,i,j+1,maxopen,open-1))
                return true;
        }
        dp[i][j][open] = true;
        return false;
    }
};