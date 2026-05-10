class Solution {
public:

    bool feasible(int mid,
                  int n,
                  vector<vector<pair<int,int>>>& adj,
                  int src,
                  int tar,
                  int k){

        deque<int> dq;

        vector<int> dist(n,INT_MAX);

        dist[src] = 0;
        dq.push_front(src);

        while(!dq.empty()){

            int u = dq.front();
            dq.pop_front();

            for(auto &[v,w] : adj[u]){

                int cost = (w > mid);

                if(dist[u] + cost < dist[v]){

                    dist[v] = dist[u] + cost;

                    if(cost==0){
                        dq.push_front(v);
                    }else{
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[tar] <= k;
    }

    int minimumThreshold(int n,
                         vector<vector<int>>& edges,
                         int source,
                         int target,
                         int k) {

        vector<vector<pair<int,int>>> adj(n);

        int hi = 0;

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

            hi = max(hi,w);
        }

        int lo = 0;
        int ans = -1;

        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            if(feasible(mid,n,adj,source,target,k)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};