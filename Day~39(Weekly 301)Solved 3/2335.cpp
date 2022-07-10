class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int a  = amount[0]+amount[1], b = amount[2];
        if(a>=b)
            return b+(a-b+1)/2;
        else
            return b;
    }
};