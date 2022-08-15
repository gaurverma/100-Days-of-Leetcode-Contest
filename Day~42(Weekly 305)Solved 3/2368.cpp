class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> visited(n,false);
        vector<vector<int>> graph(n);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for(auto i: restricted)
            visited[i] = true;
        dfs(0,graph,visited,ans);
        return ans;
    }
    
    void dfs(int src, vector<vector<int>>& graph, vector<bool>& visited, int &ans){
        if(visited[src])
            return;
        ans++;
        visited[src] = true;
        for(auto neib:graph[src]){
            dfs(neib,graph,visited,ans);
        }
        return;
    }
};