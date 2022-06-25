class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n  = matrix.size(), m = matrix[0].size();
        vector <int> rowmin,colmax;
        for(int i=0;i<matrix.size();i++){
            rowmin.push_back(*min_element(matrix[i].begin(),matrix[i].end()));
        }
        for(int j=0;j<matrix[0].size();j++){
            int res = 0;
            for(int i=0;i<matrix.size();i++)
                res = max(res,matrix[i][j]);
            colmax.push_back(res);
        }
        vector <int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(colmax[j]==matrix[i][j] && rowmin[i]==matrix[i][j])
                    ans.push_back(matrix[i][j]);
            }
        }
       // cout<<rowmin[2]<<" "<<colmax[1]<<endl;
        return ans;
    }
};