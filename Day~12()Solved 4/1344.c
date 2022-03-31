class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ahpm =  0.5,ampm = 6;
        hour = hour%12;
        int tot_min = hour*60+minutes;
        double ans  = tot_min*ahpm-minutes*ampm;
        if(ans<0)
            ans *= -1;
        return min(ans,360.0-ans);
        
        
    }
};