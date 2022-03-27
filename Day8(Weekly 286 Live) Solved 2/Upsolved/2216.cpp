class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector <int> fq;
        for(int i=0;i<nums.size();i++){
            int  cn = 1;
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                i++;
                cn++;
            }
            fq.push_back(cn);
        }
        bool odd = true;
        int ans = fq[0]-1;
        for(int i=1;i<fq.size();i++){
           if(odd){
               if(fq[i]==1)
                   odd = false;
               else
                   ans += fq[i]-2;
           }else{
                   ans += fq[i]-1;
                   odd = true;
           }
        }
        if((nums.size()-ans)&1)
            ans++;
        return ans;
    }
};