class Solution {
public:
    
    static bool cmp(vector <int> a, vector <int> b){
        return (a[1]==b[1]?a[0]<b[0]:a[1]<b[1]);
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector <vector<int>> ans;
        for(int i=0;i<people.size();i++){
            int  grtcn =  0;
            for(int j=0;j<i;j++){
                if(ans[j][0]>=people[i][0])
                    grtcn++;
            }
            if(grtcn<=people[i][1])
                ans.push_back(people[i]);
            else{
                vector <vector<int>> temp;
                int n  = ans.size()-1;
                while(grtcn!=people[i][1]){
                    if(ans[n][0]>=people[i][0])
                        grtcn--;
                    temp.push_back(ans[n]);
                    ans.pop_back();
                    n--;
                }
                ans.push_back(people[i]);
                for(int j = temp.size()-1;j>=0;j--)
                     ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};