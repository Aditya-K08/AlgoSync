class MedianFinder {
public:
    multiset<int>ms;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
    }
    
    double findMedian(){
        int sz = ms.size();
        if(sz == 0) return 0.0;

        auto it = ms.begin();
        advance(it, sz/2);

        if(sz & 1) {
            return (double)(*it);
        } else {
            auto it2 = it;
            advance(it2, -1);
            return ( (double)(*it) + (double)(*it2) ) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */