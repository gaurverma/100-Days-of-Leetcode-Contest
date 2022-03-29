class Solution {
public:
    
    vector <int> dir = {-1,1,0,1,1,-1,0,-1,-1};
    
    bool haswon(vector<vector<int>> board,int i,int j){
        int ch = board[i][j];
        
        if(i==1 && j==1){
            if((board[0][0] == ch && board[2][2]==ch)||(board[0][2]==ch && board[2][0]==ch) || (board[1][0]==ch && board[1][2]==ch)){
                return true;
            }
        }
        if(i==1){
            if(board[i-1][j]==ch && board[i+1][j]==ch)
                return true;
        }else if(j==1){
            if(board[i][j-1]==ch && board[i][j+1]==ch)
                return true;
        }
       
        for(int k=0;k<dir.size()-1;k++){
            int ti = i, tj = j,cn = 0;
            while(ti>=0 && ti<3 && tj>=0 && tj<3 && board[ti][tj]==ch){
               cn++;
               ti += dir[k];
               tj += dir[k+1];
               if(cn==3)
                  return true;
            }
        }
        
        return false;
       
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        vector <vector<int>> board(3,vector <int>(3,-1));
        string ans;
        bool Achance = true;
        for(auto move: moves){
            int i = move[0], j = move[1];
            if(Achance){
                board[i][j] = 1;
                if(haswon(board,i,j))
                    return "A";
                Achance  = false;
            }else{
                board[i][j] = 0;
                if(haswon(board,i,j)){
                     return "B";
                }
                Achance  = true;
            }
        }
        cout<<haswon(board,2,2);
        cout<<endl;
        if(moves.size()==9)
            return "Draw";
        else 
           ans  = "Pending"; 
        return ans;
    }
};