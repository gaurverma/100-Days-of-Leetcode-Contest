class Solution {
public:
    int largestInteger(int num) {
        vector <int> odd;
        vector <int> even;
        int n  = num;
        while(n){
            int t = n%10;
            n = n/10;
            if(t&1) odd.push_back(t);
            else even.push_back(t);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int i=0, j=0;
        n  = num;
        string ans;
        while(n){
            int t = n%10;
            n = n/10;
            if(t&1 && i<odd.size()) ans += to_string(odd[i++]);
            else if(t%2==0 && j<even.size()) ans += to_string(even[j++]);
            else
                 break;
        }
        reverse(ans.begin(),ans.end());
        
        return stoi(ans);
        
    }
};