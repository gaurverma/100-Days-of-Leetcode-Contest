class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<pair<int,vector<int>>> st;
        for(int i=0 ; i<words.size();i++){
            vector <int> vec(26,0);
            for(auto c:words[i]){
                vec[c-'a']++;
            }
            if(st.empty()||st.top().second!=vec){
                st.push({i,vec});
            }
        }
        
        vector<string> ans;
        while(!st.empty()){
            ans.push_back(words[st.top().first]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};