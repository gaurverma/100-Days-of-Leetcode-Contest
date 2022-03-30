class Solution {
public:
    
    bool check(vector<vector<int>> mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++)
                if(mat[i][j]==1)
                    return false;
        }
        return true;
    }
    
    
    string getkey(vector<vector<int>> mat){
        string key;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++)
                key += to_string(mat[i][j]);
        }
        return key;
    }
    
    vector<vector<int>> flip(vector<vector<int>> mat, int i,int j){
        vector<vector<int>> ans = mat;
        ans[i][j] ^=1;
        if(i>0) 
            ans[i-1][j] ^=1;
        if(i<mat.size()-1)
            ans[i+1][j] ^=1;
        if(j>0)
            ans[i][j-1] ^=1;
        if(j<mat[0].size()-1)
            ans[i][j+1] ^=1;
        return ans;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        int ans = 0;
        unordered_map <string, bool> visited;
        queue <vector<vector<int>>> q;
        q.push(mat);
        while(!q.empty()){
            int count  = q.size();
            for(int k=0;k<count;k++){
                vector <vector<int>> node = q.front();
                q.pop();
                if(check(node))
                   return ans;
                for(int i=0;i<mat.size();i++){
                    for(int j=0;j<mat[0].size();j++){
                        vector<vector<int>> child = flip(node,i,j);
                        string childkey = getkey(child);
                        if(visited[childkey])
                           continue;
                        visited[childkey] = true;
                        q.push(child);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};