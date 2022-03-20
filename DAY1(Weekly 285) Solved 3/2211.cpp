class Solution {
public:
    int countCollisions(string dir) {
        int ans  = 0;
        int n  = dir.length();
        for(int i=0;i<dir.size()-1;i++){
            if(dir[i]=='R' && dir[i+1]=='L'){
                ans += 2; 
                dir[i]='S';
                dir[i+1]='S';
                i++;
            }       
        }
       
        for(int i=1;i<dir.size();i++){
            if(dir[i]=='L' && dir[i-1]=='S'){
                ans++;
                dir[i] = 'S';
            }
        }
     
        for(int i=dir.size()-1;i>=0;i--){
            if(dir[i]=='R' && dir[i+1]=='S'){
                ans++;
                dir[i] = 'S';
            }
        }
        return ans;
    }
};