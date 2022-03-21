class Solution {
public:
    
    static string first(string c){
         string ans;
         for(int i=1;i<c.length();i++){
                if(c[i-1]==' '){
                    while(i<c.length())
                        ans += c[i++];
                    break;
                }
         }
        return ans;
    }
    
    static string zero(string c){
        string ans;
        int i=0;
        while(i<c.length() && c[i]!=' ')
                ans += c[i++];
        return ans;
    }
    
    static bool cmp(string s1,string s2){
        if(first(s1)!=first(s2))
            return first(s1)<first(s2);
        else
            return zero(s1)<zero(s2);
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector <string> dig,let;
        for(auto c:logs){
            char ch;
            for(int i=1;i<c.length();i++){
                if(c[i-1]==' '){
                    ch = c[i];
                    break;
                }
            }
            if(ch>='0' && ch<='9')
                dig.push_back(c);
            else
                let.push_back(c);
        }
        sort(let.begin(),let.end(),cmp);
        for(auto c:dig){
            let.push_back(c);
        }
        return let;
    }
};