class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        set <string> st;
        for(int i=0;i<=s.length();i++){
            st.insert(s.substr(0,i));
        }
        int ans  = 0;
        for(auto w:words){
            if(st.find(w)!=st.end())
                ans++;
        }
        return ans;
    }
};