class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string  n  = to_string(num);
        int ans = 0;
        for(int i=0;i<n.length()-k+1;i++){
            int t = stoi(n.substr(i,k));
            if(t!=0 && num%t==0)
                ans++;
        }
        return ans;
    }
};