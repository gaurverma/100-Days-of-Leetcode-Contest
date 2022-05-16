class Solution {
public:
    string removeDigit(string number, char digit) {
        int idx = -1;
        for(int i=0;i<number.length()-1;i++){
            if(number[i]==digit){
                if(number[i]<number[i+1]){
                    idx = i;
                    break;
                }else{
                    idx = i;
                }
            }    
        }
        if(number[number.length()-1]==digit && (idx==-1 ||number[idx]>=number[idx+1]))
            idx = number.length()-1;
        string ans;
        for(int i=0;i<number.length();i++){
            if(i!=idx)
                ans += number[i];
        }
        return ans;
    }
};