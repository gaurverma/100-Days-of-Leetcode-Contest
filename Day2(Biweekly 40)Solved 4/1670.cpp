class FrontMiddleBackQueue {
public:
    vector <int> queue;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        vector <int> temp;
        temp.push_back(val);
        for(auto c:queue)
            temp.push_back(c);
        queue = temp;
    }
    
    void pushMiddle(int val) {
        int mid = (queue.size())/2;
        vector <int> temp;
        for(int i=0;i<mid;i++){
            temp.push_back(queue[i]);
        }
        temp.push_back(val);
        for(int i=mid;i<queue.size();i++){
            temp.push_back(queue[i]);
        }
        queue = temp;
    }
    
    void pushBack(int val) {
        queue.push_back(val);
    }
    
    int popFront() {
        if(!queue.size()) return -1;
        int val = queue[0];
        for(int i=0;i<queue.size()-1;i++)
            queue[i] = queue[i+1];
        queue.pop_back();
        return val;
    }
    
    int popMiddle() {
        if(!queue.size()) return -1;
        int mid = (queue.size()-1)/2;
        int val = queue[mid];
        for(int i=mid;i<queue.size()-1;i++){
            queue[i] = queue[i+1];
        }
        queue.pop_back();
        
        return val;
    }
    
    int popBack() {
        if(queue.size()){
            int val = queue[queue.size()-1];
            queue.pop_back();
            return val;
        }
        return -1;
    }
};
