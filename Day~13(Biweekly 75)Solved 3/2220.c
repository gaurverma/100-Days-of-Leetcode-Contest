class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start || goal){
            if(start==goal)
                return ans;
            if((start&1) != (goal&1))
                ans++;
            start /=2;
            goal /=2;
        }
        return ans;
    }
};