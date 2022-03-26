class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cn = 0;
        vector <bool> visited(3000,0);
        for(auto num:arr){
           visited[num] = 1;
        }
        for(int i=1;i<3000;i++){
            if(visited[i]==false)
                cn++;
            if(cn==k)
                return i;
        }
        return 0;
    }
};