class Solution {
public:
    int ans  = 0;
   
    int numTeams(vector<int>& ratings) {
        vector <int> smallerL(ratings.size(),0),smallerR(ratings.size(),0);
        for(int i=0;i<ratings.size();i++){
            for(int j=i-1;j>=0;j--){
                if(ratings[j]<ratings[i])
                    smallerL[i]++;
            }
            for(int j=i+1;j<ratings.size();j++){
                if(ratings[j]<ratings[i])
                    smallerR[i]++;
            }
        } 
         for(int i=0;i<ratings.size();i++){
            for(int j=i-1;j>=0;j--){
                if(ratings[j]<ratings[i])
                    ans += smallerL[j];
            }
            for(int j=i+1;j<ratings.size();j++){
                if(ratings[j]<ratings[i])
                    ans += smallerR[j];
            }
         }
        
        return ans;
    }
};