class Solution {
public:
    
    bool isvalid(string p, string s1, string s2){
        if(s1.length()%p.length()!=0 || s2.length()%p.length()!=0)
            return false;
        for(int i=0;i<s1.length();i+=p.length()){
            if(s1.substr(i,p.length())!=p)
                return false;
        }
        for(int i=0;i<s2.length();i+=p.length()){
            if(s2.substr(i,p.length())!=p)
                return false;
        }
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        int start = 1, end = max(str1.length(),str2.length());
        string ans  = "";
        for(int i=1;i<=str1.length();i++){
            if(isvalid(str1.substr(0,i),str1,str2))
                ans = str1.substr(0,i);
        }
        return ans;
    }
};