class Solution {
public:
    bool isvalid(vector<int> v){
        if(v['a'-'a'] && v['e'-'a'] && v['i'-'a'] && v['o'-'a'] && v['u'-'a'])
            return  true;
        return false;
    }
    
  
    
    int countVowelSubstrings(string word) {
        int ans = 0;
        for(int i=0;i<word.length();i++){
            vector <int> v(26,0);
            int j=i;
            while(isvowel(word[j])){
                v[word[j]-'a']++;
                if(isvalid(v))
                   ans++;
                j++;
            }
        }
        return ans;
    }
};