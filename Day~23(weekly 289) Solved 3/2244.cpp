class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map <int,int> fq;
        for(auto task:tasks)
            fq[task]++;
        int ans = 0;
        for(auto p:fq){
            int val = p.second;
            if(val==1) return -1;
            if(val%3==0)
                ans  += val/3;
            else
                ans  += val/3+1;
        }
        return ans;
    }
};