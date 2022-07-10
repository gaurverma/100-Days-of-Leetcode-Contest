class SmallestInfiniteSet {
public:
    priority_queue <int,vector<int>, greater<int>> pq;
    unordered_map <int,int> mp;
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++){
            mp[i] = 1;
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int ans = pq.top();
        pq.pop();
        mp[ans] = 0;
        return ans;
    }
    
    void addBack(int num) {
        if(mp[num]==0){
            mp[num]=1;
            pq.push(num);
        }
          
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */