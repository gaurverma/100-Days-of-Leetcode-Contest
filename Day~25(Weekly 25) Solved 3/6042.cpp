class Solution {
public:
    
   bool eDis(double x,double y,double i, double j, int r){
        double d = sqrt(pow((x-i),2)+pow((y-j),2));
        if(d<=r) return true;
        return false;
    }
    
    
    int countLatticePoints(vector<vector<int>>& circles) {
        set <pair<int,int>> s;
             for(auto circle:circles){
                 int x= circle[0], y = circle[1], r = circle[2];
                 for(int i = x-r;i<=x+r;i++){
                     for(int j=y-r;j<=y+r;j++)
                         if(eDis(x,y,i,j,r))
                            s.insert({i,j});
                 }
             }
        return s.size();
    }
};