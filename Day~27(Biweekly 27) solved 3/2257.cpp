class Solution {
public:
    vector <int> dir = {-1,0,1,0,-1};
    
    bool isvalid(int i,int j, int m ,int n){
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector <vector<int>> grid(m,vector<int>(n,0));
        for(auto w:walls){
            grid[w[0]][w[1]] = -1;
        }
        for(auto g:guards){
            int i = g[0], j = g[1];
            grid[i][j] = 1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=-1 && isvalid(i,j-1,m,n)  && grid[i][j-1]==1)
                    grid[i][j] = 1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=-1 && isvalid(i,j+1,m,n)  && grid[i][j+1]==1)
                    grid[i][j] = 1;
            }
        }
        for(auto g:guards){
            int i = g[0], j = g[1];
            grid[i][j] = 2;
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j]!=-1 && isvalid(i-1,j,m,n)  && grid[i-1][j]==2)
                    grid[i][j] = 2;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=m-1;i>=0;i--){
                if(grid[i][j]!=-1 && isvalid(i+1,j,m,n) && grid[i+1][j]==2)
                    grid[i][j] = 2;
            }
        }
      
        
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    ans++;
            }
        }
        return ans;
    }
};