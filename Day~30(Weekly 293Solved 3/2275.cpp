class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector <int> bits(32,0);
        for(auto c:candidates){
            int i=0;
            while(c){
                if(c&1) bits[i]++;
                c >>= 1;
                i++;
            }
        }
        int ans = *max_element(bits.begin(),bits.end());
        return ans;
    }
};