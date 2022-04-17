class Solution {
public:
    string digitSum(string s, int k) {
        if(s.length()<=k)
            return s;
        string ans;
        int i = 0,j=0;
        while(i<s.length()){
            int num = 0;
            for(;j<k+i && j<s.length();j++)
                num += (s[j]-'0');
            ans += to_string(num);
            i = j;
        }
        if(ans.length()>k)
            return digitSum(ans,k);
        return ans;
    }
};