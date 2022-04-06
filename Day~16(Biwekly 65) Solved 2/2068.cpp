class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector <int> mp1(26,0),mp2(26,0);
        for(auto c:word1){
            mp1[c-'a']++;
        }
        for(auto c:word2){
            mp2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(abs(mp1[i]-mp2[i])>3)
                return false;
        }
        return true;
    }
};