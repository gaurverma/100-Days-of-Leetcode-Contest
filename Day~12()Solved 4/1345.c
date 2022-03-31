class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int i=0;
        for(auto num:arr){
            mp[num].push_back(i);
            i++;
        }
        queue <int> q;
        q.push(0);
        int ans  = 0;
        vector <bool> visited(arr.size(),false);
        unordered_map <int,bool> black;
        
        visited[0]  = true;
        while(!q.empty()){
            int count = q.size();
            while(count--){
                int t = q.front();
                q.pop();
                if(t==arr.size()-1)
                    return ans;
                if(t>0 && visited[t-1]==false){
                    q.push(t-1);
                    visited[t-1] = true; 
                }
                  
                if(t<arr.size()-1 && visited[t+1]==false){
                    q.push(t+1);
                    visited[t+1] = true;
                }
                
                if(black[arr[t]]==false){
                    for(auto idx:mp[arr[t]]){
                        if(visited[idx]==false){
                           q.push(idx);
                           visited[idx] = true;
                        }
                    }
                    black[arr[t]] = true;
                }
                
            }
            ans++;
        }
        return ans;
    }
};