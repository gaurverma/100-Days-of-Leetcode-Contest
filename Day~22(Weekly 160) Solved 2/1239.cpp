class Solution {
public:
    int maxLength(vector<string>& arr) {
        set <set<char>> s;
        set <char> t;
        s.insert(t);
        for(auto str:arr){
            for(auto st:s){
                int l = st.size();
                set <char> temp = st;
                for(char c:str){
                    temp.insert(c);
                }
                if(temp.size()==(st.size()+str.length()))
                   s.insert(temp);
            }
        }
        int ans  = 0;
        for(auto st:s){
            int t  = st.size();
            ans  = max(ans,t);
        }
        return ans;
    }
};