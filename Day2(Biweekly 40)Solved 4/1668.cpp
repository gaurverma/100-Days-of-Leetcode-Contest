class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int wl = word.length(), sl = sequence.length();
        int ans=0;
        for(int i=0;i<sl;i++){
            int k=0;
            int j=i;
            while(j+wl<=sl && (sequence.substr(j,wl)==word)){
                k++;
                j = j+wl;
            }
            ans  = max(ans,k);
        }
        return ans;
    }
};