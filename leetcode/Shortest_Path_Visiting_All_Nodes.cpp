class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<bool>>visited(n,vector<bool>(1<<n));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            visited[i][1<<i]=true;
        }
        while(!q.empty()){
            auto [u,mask,d]=q.front();
            q.pop();
            if(mask==((1<<n)-1)) return d;
            for(int v:graph[u]){
                int newmask=mask|(1<<v);
                if(!visited[v][newmask]){
                    q.push({v,newmask,d+1});
                    visited[v][newmask]=true;
                }
            }
        }
        return -1;
    }
};