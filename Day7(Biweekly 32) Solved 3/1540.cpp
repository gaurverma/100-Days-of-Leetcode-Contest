class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length()!=t.length())
            return false;
        vector <int> op(27,k/26);
        for(int i=1;i<=k%26;i++)
            op[i]++;
        for(int i=0;i<s.length();i++){
            if(s[i]==t[i]) continue;
            int diff = (t[i]-s[i]+26)%26;
            if(op[diff]) 
                op[diff]--;
            else
                return false;
        }
        return true;
    }
};