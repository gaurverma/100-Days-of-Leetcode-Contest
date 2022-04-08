class Solution {
public:
    
    vector <int> dir = {-1,0,1,0,-1};
     
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> visited(maze.size(),vector <bool> (maze[0].size(),false));
        queue <pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        if(maze[entrance[0]][entrance[1]]=='+')
            return -1;
        int ans = 0;
        while(!q.empty()){
            int cn = q.size();
            while(cn--){
                 pair<int,int> p = q.front();
                 q.pop();
                 int i = p.first, j = p.second;
                if(i==entrance[0] && j==entrance[1]){

                }else if((i==maze.size()-1 || j==maze[0].size()-1 || i==0 || j==0))
                     return ans;
                 for(int k=1;k<5;k++){
                     int nxi = i+dir[k-1], nxj = j+dir[k];
                     if(nxi>=maze.size() || nxj>=maze[0].size() || visited[nxi][nxj]==true || maze[nxi][nxj]=='+')
                         continue;
                     q.push({nxi,nxj});
                     visited[nxi][nxj] = true;
                    
                 }
            }
            ans++;
        }
        return -1;
    }
};