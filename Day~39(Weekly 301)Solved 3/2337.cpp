class Solution {
public:
    bool canChange(string s, string t) {
        if(count(s.begin(),s.end(),'L')!=count(t.begin(),t.end(),'L') || count(s.begin(),s.end(),'R')!=count(t.begin(),t.end(),'R'))
            return false;
        string a, b;
        for(auto c:s)
            if(c!='_')
                a += c;
        for(auto c:t)
            if(c!='_')
                b += c;
        //cout<<a<<" "<<b<<endl;
        if(a!=b)
            return false;
        vector<vector<int>> lp;
        int space = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='_')
                space++;
            else if(s[i]=='R')
                space = 0;
            else if(s[i]=='L'){
                lp.push_back({i-space,i});
            }
        }
        vector<vector<int>> rp;
        space = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='_')
                space++;
            else if(s[i]=='L')
                space = 0;
            else if(s[i]=='R'){
                rp.push_back({i,i+space});
            }
        }
        reverse(rp.begin(),rp.end());
        int l = 0, r = 0;
        for(int j=0;j<t.size();j++){
            if(t[j]=='L'){
                if(j>=lp[l][0] && j<=lp[l][1])
                   l++;
                else
                    return false;
            }else if(t[j]=='R'){
                if(j>=rp[r][0] && j<=rp[r][1])
                   r++;
                else
                    return false;
            }
        }
        return true;
    }
};