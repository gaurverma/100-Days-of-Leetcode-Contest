class Solution {
public:
    vector <string> ans;
    
    
    void helper(int n, int& start){
         if(n==1){
            int first = start&1;
            int second = first^1;
            ans  = {to_string(first),to_string(second)};
            start >>= 1;
            return;
        }
        helper(n-1,start);
        vector<string> temp = ans;
        for(int i=temp.size()-1;i>=0;i--)
            ans.push_back(temp[i]);
        int first = start&1;
        int second = first^1;
        start >>=1;
        int i=0;
        for(;i<temp.size();i++)
            ans[i] = to_string(first)+ans[i];
        for(;i<ans.size();i++)
            ans[i] = to_string(second)+ans[i];
        return;
    }
    
    vector<int> circularPermutation(int n, int start) {
        vector <int> res;
        helper(n,start);
        for(auto s:ans)
            res.push_back(stoull(s, 0, 2));
        return res;
    }
};