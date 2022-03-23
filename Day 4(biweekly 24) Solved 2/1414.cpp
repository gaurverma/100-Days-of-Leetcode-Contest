class Solution {
public:
 
    int findMinFibonacciNumbers(int k) {
        vector <int> fibo = {0,1};
        int i=1;
        while(fibo[i]<k){
            i++;
            fibo.push_back(fibo[i-1]+fibo[i-2]);
        }
        int ans  = 0;
        while(k && i>=0){
            if(fibo[i]<=k){
                 k -= fibo[i];
                 ans++;
            }
            i--;
        }
        return ans;
    }
};