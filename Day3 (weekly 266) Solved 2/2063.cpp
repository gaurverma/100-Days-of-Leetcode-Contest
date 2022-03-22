class Solution {
public:
    typedef long long LL;
    
    bool isvowel(char ch) { return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u'); }
    
    LL nfs(LL n){
        return ceil((long double)n*(n+1)/2);
    }
    
    long long countVowels(string word) {
        LL ans  = 0;
        LL  n =  word.length();
        LL total  = nfs(n);
        for(int i=0;i<word.length();i++){
            if(isvowel(word[i])){
                ans += (total-nfs(i)-nfs(n-i-1));
            }
        }
        return ans;
    }
};