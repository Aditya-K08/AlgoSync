class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> vis;

        pq.push(1);
        vis.insert(1);

        long long x = 1;

        for(int i = 0; i < n; i++){
            x = pq.top(); pq.pop();

            if(!vis.count(x*2)){
                pq.push(x*2);
                vis.insert(x*2);
            }
            if(!vis.count(x*3)){
                pq.push(x*3);
                vis.insert(x*3);
            }
            if(!vis.count(x*5)){
                pq.push(x*5);
                vis.insert(x*5);
            }
        }
        return x;
    }
};