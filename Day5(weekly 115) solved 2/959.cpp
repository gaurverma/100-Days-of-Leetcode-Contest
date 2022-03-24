vector <int> change (vector<int>  cells){
        vector <int> ans(8,0);
        for(int i=1;i<7;i++){
            if(cells[i-1]==cells[i+1])
                ans[i] = 1;
        }
        return ans;
    }
    
    string getkey(vector <int> temp){
        string ans;
        for(auto t:temp)
            ans += '0'+t;
        return ans;
    }
    
 
    
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int cycle  = 1;
        
        unordered_map <string,int> mp;
        unordered_map<int,string> rvmp;
        
        cells = change(cells);
        n--;
        
        rvmp[1] = getkey(cells);
        mp[getkey(cells)] = 1;
        
        vector <int> temp = cells;
        int breakpoint;
        
        int i=1;
        while(true){
            temp = change(temp);
            if(mp[getkey(temp)]){
                breakpoint = mp[getkey(temp)];
                break;
            }
            else{
                 mp[getkey(temp)] = i;
                 rvmp[1] = getkey(temp);
            }
            i++;
        }
        
        vector <int> brk = temp;
        
        while(true){
            temp = change(temp);
            if(temp==brk)
                break;
            cycle++;
        }
        vector <int> ans  = cells;
        while(--breakpoint && n--){
            ans  = change(ans);
        }
        n = n%cycle;
        if(n==0)
            return brk;
        while(n--){
            ans = change(ans);
        }
        return ans;
    }
};