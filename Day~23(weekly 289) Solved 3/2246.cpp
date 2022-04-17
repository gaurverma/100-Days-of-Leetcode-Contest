class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int  m = parent.size();
        vector<vector<int>> g(m);
        for(int i=1;i<parent.size();i++)
            g[parent[i]].push_back(i);
        dfs(g,0,s);
        return  ans;
    }
    
    int ans = 0;
    
    int dfs(vector<vector<int>>& g,int src,string& s){
        int mxval = 0,mnval = 0;
        for(int i=0;i<g[src].size();i++){
            int temp = g[src][i];
            int val = dfs(g,temp,s);
            if(s[temp]!=s[src]){
                if(val>mxval){
                    mnval = mxval;
                    mxval = val;
                }else if(val>mnval){
                    mnval = val;
                }
            }
        }
        int res = 1+mxval+mnval, rval = mxval+1;
        ans = max(ans,res); 
        return rval;
    }
    
};