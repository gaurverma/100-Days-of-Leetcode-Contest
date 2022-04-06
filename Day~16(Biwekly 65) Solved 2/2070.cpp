class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int price = 0;
        for(int i=0;i<items.size();i++){
            price = max(price,items[i][1]);
            items[i][1] = price;
        }
        vector <int> ans;
        for(auto i:queries){
            int start = 0, end = items.size()-1;
            int res = 0;
            while(start<=end){
                int mid = end-(end-start)/2;
                if(items[mid][0]<=i){
                    res = items[mid][1];
                    start = mid+1;
                }else
                    end = mid-1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};