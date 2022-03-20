class Solution {
public:
    vector <int> ans;
    int maxscore = 0;
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector <int> temp;
        helper(numArrows,aliceArrows,temp,0,0);
        return ans;
    }
    
    void helper(int numArrows, vector<int>& aliceArrows,vector <int> atn, int score , int scoretillnow){
         if(score==12){
             if(scoretillnow>maxscore){
                 atn[0] = numArrows;
                 ans = atn;
                 maxscore = scoretillnow;
             } 
             return;
         }
         atn.push_back(0);
         helper(numArrows,aliceArrows,atn,score+1,scoretillnow);
         atn.pop_back();
         if(aliceArrows[score]<numArrows){
             numArrows -= aliceArrows[score]+1;
             scoretillnow += score;
             atn.push_back(aliceArrows[score]+1);
             helper(numArrows,aliceArrows,atn,score+1,scoretillnow);
         }
         
    }
};