class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0)
            return 0;
        if(k==0){
           if(num%10==0)
               return 1;
            return -1;
        }
        int numU = num%10;
        int ans = -1;
        int s = 1;
        for(int i=1;i<10;i++){
            s = k*i;
            if(s%10==numU){
                if(k*i<=num)
                    return i;
                return -1;
            }
        }
        if(num%10==0 && k*10<=num)
            return 10;
        return -1;
    }
};