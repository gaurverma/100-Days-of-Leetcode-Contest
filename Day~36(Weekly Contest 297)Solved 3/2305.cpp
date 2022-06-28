class Solution {
public:
    int ans = 100000000;
    bool solve(vector<int>& a,int k, int index,int maxsum,vector<int>& partitions){
        if(index==a.size())
            return true;
        for(int i=0;i<k;i++){
            if(partitions[i]+a[index]<=maxsum){
                partitions[i]+=a[index];
                if(solve(a,k,index+1,maxsum,partitions))
                    return true;
                partitions[i]-=a[index];
            }
        }
        return false;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int beg = 0;
        int end = 0;
        for(auto i:cookies)
            end += i;
        int pans  = end;
        while(beg<=end){
            int mid = end-(end-beg)/2;
             vector <int> partitions(k,0);
            if(solve(cookies,k,0,mid,partitions)){
                pans = mid,
                end = mid-1;
            }else
                beg = mid+1;
        }
        return pans;
    }
};