class Solution {
public:
    int minInsertions(string str) {
        int ans  = 0;
        stack <int> s;
        for(int i=0;i<str.length();i++){
            if(str[i]=='(')
                s.push(str[i]);
            else{
                if(s.empty())
                   ans++;
                else
                   s.pop();
                if(i<str.length() && str[i+1]==')')
                    i++;
                else 
                    ans++;
            }
        }
        while(!s.empty()){
            ans += 2;
            s.pop();
        }
        return ans;
    }
};