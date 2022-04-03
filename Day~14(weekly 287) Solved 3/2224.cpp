class Solution {
public:
    
    int minutes(string current){
        string hour, mn;
        int hr,min;
        hour = current.substr(0,2);
        mn = current.substr(3,2);
        hr = stoi(hour);
        min = stoi(mn);
        return hr*60+min;
    }
    
    int convertTime(string current, string correct) {
        int tot = 24*60;
        int diff = (minutes(correct)-minutes(current)+tot)%tot;
        int ans  = 0;
        while(diff){
            if(diff>=60)
                diff -= 60;
            else if(diff>=15)
                diff -= 15;
            else if(diff>=5)
                diff -= 5;
            else
                diff--;
            ans++;
        }
        return ans;
    }
};