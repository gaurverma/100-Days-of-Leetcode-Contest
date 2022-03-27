class Solution {
public:
    typedef long long LL;
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int  val = (intLength-1)/2;
        LL tot = 9 * pow(10,val);
        vector <LL> res;
        for(auto i:queries){
            if(i>tot){
                res.push_back(-1);
                continue;
            }
            int  t = ceil(double(i)/pow(10,val));
            string ans = to_string(t);
            
            LL next = i-(t-1)*(pow(10,val))-1;
            string ans_next = to_string(next);
            while(ans.length()+ans_next.length()<=val){
                ans += '0';
            }
            if(ans.length()<intLength-1)
               ans += to_string(next);
            if(intLength&1){
                int j = ans.length()-2;
                while(ans.length()<intLength && j>=0)
                    ans += ans[j--];
            }else{
                int j = ans.length()-1;
                while(ans.length()<intLength && j>=0)
                    ans += ans[j--];
            }
            LL temp = stol(ans, nullptr, 10);
            res.push_back(temp);
        }
        return res;
    }
};