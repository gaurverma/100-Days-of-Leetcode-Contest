class Solution {
public:
    
    bool cmp(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    
    
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
       
        
        int i=0,j=0;
        int ans = 0;
        int cn = 0;
        
        while(j<tiles.size()){
            
            if(tiles[j][1]-tiles[j][0]+1>=carpetLen)
                return carpetLen;
            
            cn += (tiles[j][1]-tiles[j][0]+1);
            
            while(tiles[j][1]-tiles[i][0]+1>carpetLen){
                cn -= (tiles[i][1]-tiles[i][0]+1);
                i++;
            }
            
            int t = -1;
            if(i>0){
                int low = tiles[i-1][0];
                int high = tiles[i-1][1];
                while(low<=high){
                    int mid =  high-(high-low)/2;
                    if(tiles[j][1]-mid+1<=carpetLen){
                        t = mid;
                        high = mid-1;
                    }else
                        low = mid+1;
                }
            }
            

            ans  = max(ans,cn+(t==-1?0:tiles[i-1][1]-t+1));
            j++;
            
            
        }
        return ans;
    }
};