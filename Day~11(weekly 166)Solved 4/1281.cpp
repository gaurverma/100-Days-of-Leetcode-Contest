class Solution {
public:
    int subtractProductAndSum(int n) {
        if(n==0) return 0;
        int prod =1, sum = 0;
        while(n){
            prod *= n%10;
            sum += n%10;
            n = n/10;
        }
        return prod-sum;
    }
};