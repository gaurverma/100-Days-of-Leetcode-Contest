class Solution {
public:
    string smallestNumber(string pattern) {
        unordered_map<int,bool> mp;
        int n = pattern.length()+1;
        string ans = "";
        for(int i=1;i<=n;i++){
            ans += to_string(i);
            mp[i] = true;
            int back = ans.back()-'0';
            if(helper(ans,pattern,mp,0))
                return ans;
            mp[i] = false;
            ans.pop_back();
        }
        return ans;
    }
    
    bool helper(string &ans, string &pattern , unordered_map<int,bool>& mp, int idx){
        if(idx==pattern.length()){
            return true;
        }
        for(int i=1;i<=9;i++){
            int back = ans.back()-'0';
            if(mp[i]==false && ((pattern[idx]=='I' && i>back)||(pattern[idx]=='D' && i<back))){
               ans += to_string(i);
               mp[i] = true;
               if(helper(ans,pattern,mp,idx+1))
                 return true;
               mp[i] = false;
               ans.pop_back();    
            }
        }
        return false;
    }
    
};