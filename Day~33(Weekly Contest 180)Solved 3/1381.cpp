class CustomStack {
public:
    vector <int> stck;
    int maxsize;
    CustomStack(int maxSize) {
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(stck.size()<maxsize)
            stck.push_back(x);
    }
    
    int pop() {
        if(stck.size()){
           int ans =  stck.back();
            stck.pop_back();
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<stck.size() && i<k; i++)
            stck[i]+=val;
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */