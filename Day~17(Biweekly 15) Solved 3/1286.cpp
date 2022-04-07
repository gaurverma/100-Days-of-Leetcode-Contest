class CombinationIterator {
public:
    vector <string> vec;
    int counter = 0;
    int mx = 10007;
    
    void generator(string s,int len,string asf){
        if(len==0){
            vec.push_back(asf);
            return;
        }
        for(int i=0;i<=s.size()-len && vec.size()<mx;i++){
            generator(s.substr(i+1),len-1,asf+s[i]);
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        generator(characters,combinationLength,"");
    }
    
    string next() {
       // cout<<vec.size()<<endl;
        return vec[counter++];
    }
    
    bool hasNext() {
        if(counter==vec.size())
            return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */