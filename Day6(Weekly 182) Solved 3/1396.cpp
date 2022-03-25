class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    unordered_map <int,pair<string,int>> Instation;
    unordered_map <string,vector<int>> timings;
    
    void checkIn(int id, string stationName, int t) {
        Instation[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string in = Instation[id].first;
        int t1 = Instation[id].second;
        timings[in+"#"+stationName].push_back(t-t1);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector <int> timing = timings[startStation+"#"+endStation];
        double sum = 0;
        for(auto time:timing){
            sum += double(time);
        }
        return sum/timing.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */