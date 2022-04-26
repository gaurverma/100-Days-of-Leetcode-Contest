class Solution {
public:
    int countGoodSubstrings(string s) {
        set<char> st;
        for(int i=0;i<3 && i<s.length();i++)
            st.insert(s[i]);
        int ans  = 0;
        for(int i=3;i<s.length();i++){
            if(st.size()==3)
                ans++;
            if(s[i-3]!=s[i-2] && s[i-3]!=s[i-1])
               st.erase(s[i-3]);
            st.insert(s[i]);
        }
        if(st.size()==3) ans++;
        return ans;
    }
};