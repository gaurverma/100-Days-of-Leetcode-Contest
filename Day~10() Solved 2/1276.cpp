class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector <int> ans;
        if(tomatoSlices & 1) return ans;
        int mn = double(tomatoSlices)/4;
        int mx = tomatoSlices/2;
        if(cheeseSlices<mn || cheeseSlices>mx) return ans;
        int small = 0 , big = 0;
        while(cheeseSlices!=tomatoSlices/2){
            big++;
            cheeseSlices--;
            tomatoSlices -= 4;
        }
            small = cheeseSlices;
        ans.push_back(big);
        ans.push_back(small);
        return ans;
    }
};