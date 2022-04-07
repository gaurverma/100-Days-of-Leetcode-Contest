class Solution {
public:
    
    static bool cmp(vector <int> a, vector <int> b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        stack <vector<int>> s;
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto i: intervals){
            if(s.empty())
                s.push(i);
            else{
                vector <int> t = s.top();
                if(t[0]<=i[0] && t[1]>=i[1])
                    continue;
                else
                    s.push(i);
            }
        }
        return s.size();
    }
};