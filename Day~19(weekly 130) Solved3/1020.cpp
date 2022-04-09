class Solution {
public:
    
    typedef vector<vector<int>> vvi;
    typedef vector <vector<bool>> vvb;
    vector <int> dir = {-1,0,1,0,-1};
    //i<0||j<0||i==grid.size()||j==grid[0].size()||
    
    void dfs(vvi &grid,vvb &visited,int i, int j ){
        if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || visited[i][j]==true || grid[i][j]==0)
            return;
        visited[i][j] = true;
        for(int k=1;k<5;k++){
            dfs(grid,visited,i+dir[k-1],j+dir[k]);
        }
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();
        int ans = 0;
        vvb visited(m,vector<bool>(n,false));
        
        
        for(int j=0;j<n;j++){
            if(visited[0][j]==false && grid[0][j]==1){
                dfs(grid,visited,0,j);
            }
        }
        
        for(int j=0;j<n;j++){
            if(visited[m-1][j]==false && grid[m-1][j]==1){
                dfs(grid,visited,m-1,j);
            }
        }
        
        for(int i=0;i<m;i++){
            if(visited[i][0]==false && grid[i][0]==1){
                dfs(grid,visited,i,0);
            }
        }
        
        for(int i=0;i<m;i++){
            if(visited[i][n-1]==false && grid[i][n-1]==1){
                dfs(grid,visited,i,n-1);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1 && visited[i][j]==false)
                    ans++;
        }
        
        
        return ans;
    }
};