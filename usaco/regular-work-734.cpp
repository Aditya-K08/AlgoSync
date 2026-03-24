#include<bits/stdc++.h>
using namespace std;
#define int long long

struct DSU{
    vector<int> p,sz;
    DSU(int n){
        p.resize(n+1);
        sz.assign(n+1,1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        return true;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("closing.in");
    ofstream cout("closing.out");

    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> order(n);
    for(int i=0;i<n;i++) cin>>order[i];

    vector<string> ans(n);
    vector<int> active(n+1,0);

    DSU dsu(n);
    int components=0;

    for(int i=n-1;i>=0;i--){
        int u=order[i];
        active[u]=1;
        components++;

        for(int v:adj[u]){
            if(active[v]){
                if(dsu.unite(u,v)) components--;
            }
        }

        ans[i]=(components==1?"YES":"NO");
    }

    for(auto &s:ans) cout<<s<<"\n";
}