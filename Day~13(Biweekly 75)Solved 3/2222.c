class Solution {
public:
    
    long long helper(string s){
        vector <int> zc(s.length(),0);
        int t = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                t++;
            zc[i] = t;
        }
        long long ans = 0;
        for(int i=1;i<s.length()-1;i++){
            if(s[i]=='0')
                continue;
            long long  zl = zc[i-1],zr = zc[s.length()-1]-zc[i];
            ans += zl*zr;
        }
        return ans;
    }
    
    long long numberOfWays(string s) {
        long long ans= 0;
        ans += helper(s);
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        ans += helper(s);
        return ans;
    }
};