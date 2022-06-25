class Solution {
public:
    string greatestLetter(string s) {
        unordered_map <char,bool> lower,upper;
        char ans = '#';
        for(auto c:s){
            if(c>='A' && c<='Z')
                 upper[c]=true;
            else
                lower[toupper(c)]=true;
            c = toupper(c);
            if(upper[c] && lower[c]){
                if(ans=='#')
                    ans = c;
                else if(ans<toupper(c))
                    ans  = c;
            }
        }
        if(ans=='#')
            return "";
        string res;
        res += ans;
        return res;
    }
};