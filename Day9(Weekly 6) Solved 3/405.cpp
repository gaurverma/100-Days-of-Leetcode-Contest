class Solution {
public:
    string toHex(int n) {
        unsigned int num = n;
        if(num==0)
            return "0";
        string ans;
        while(num){
            int rem = num%16;
            num = num/16;
            if(rem<10)
                ans += to_string(rem);
            else
                ans += 'a' + (rem-10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};