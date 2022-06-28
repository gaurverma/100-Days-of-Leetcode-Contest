class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans  = 0;
        int prev = 0;
        for(int i=0;i<brackets.size();i++){
            int upper = brackets[i][0], percent  = brackets[i][1];
            if(prev>=income)
                break;
            ans += ((min(upper,income)-prev)*percent)/100.0;
            prev = upper;
        }
        return ans;
    }
};