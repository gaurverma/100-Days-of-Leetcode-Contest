class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        vector <int> prefix(nums.size()+1,0);
        
        for(int i=1;i<=nums.size();i++){
            prefix[i] = prefix[i-1];
            if(nums[i-1]%p==0)
                prefix[i]++;
        }
        int ans = 0;
        unordered_map<string,bool> s;
        
        string prefstring;
        vector<int> strlen  = {0};
        for(int k=0;k<nums.size();k++){
            prefstring += to_string(nums[k])+"#";
            strlen.push_back(prefstring.length());
        }
            
        
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(prefix[j+1]-prefix[i]<=k){
                    string temp = prefstring.substr(strlen[i],strlen[j+1]-strlen[i]);
                    s[temp] = true;
                }
            }
        }
        return s.size();
    }
};