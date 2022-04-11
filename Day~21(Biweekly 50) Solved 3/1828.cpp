class Solution {
public:
    int eDis(double x,double y,double i, double j, int r){
        double d = sqrt(pow((x-i),2)+pow((y-j),2));
        if(d<=r) return 1;
        return 0;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
       
        vector <int> ans;
        for(auto q:queries){
            int x = q[0],y = q[1], r=q[2];
            int res = 0;
            for(auto point:points)
                res += eDis(x,y,point[0],point[1],r);
            ans.push_back(res);
        }
        return ans;
    }
};