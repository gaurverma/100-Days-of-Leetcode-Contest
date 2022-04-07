class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map <int,int> fq;
        int mx = 0;
        int ele;
        for(int i:arr){
            fq[i]++;
            if(fq[i]>mx){
                mx = fq[i];
                ele = i;
            }
        }
        return ele;
    }
};