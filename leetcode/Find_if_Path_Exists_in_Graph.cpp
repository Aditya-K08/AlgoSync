class DSU{
    public:

    int n;
    vector<int>parent,sz;
    DSU(int n) : n(n),parent(n),sz(n,1){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(sz[u]<sz[v]) swap(u,v);
        parent[v]=u;
        sz[u]+=sz[v];
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto e:edges){
            dsu.unite(e[0],e[1]);
        }
        return dsu.find(source)==dsu.find(destination);
    }
};