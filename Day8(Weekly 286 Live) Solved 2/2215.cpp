class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> m1,m2,m3,m4;
        for(int num:nums1)
            m1[num]++;
         for(int num:nums2)
            m2[num]++;
        vector <int> ans1,ans2;
        for(int num:nums1){
            if(m2[num]==0 && m3[num]==0){
                 ans1.push_back(num);
                 m3[num]++;
            }
               
        }
        for(int num:nums2){
            if(m1[num]==0 && m4[num]==0){
                ans2.push_back(num);
                m4[num]++;
            }
               
        }
        vector <vector<int>> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
    
};