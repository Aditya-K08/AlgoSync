#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

struct Edge{
    int u,v,w;
};

int n,m,d;
vector<Edge> edges;
vector<vector<pair<int,int>>> adj;

bool feasible(int X){
    vector<int> dp(n+1,1e18);
    vector<int> par(n+1,-1);

    dp[1]=0;

    for(int u=1;u<=n;u++){
        if(dp[u] > d) continue;

        for(auto &e:adj[u]){
            int v=e.first;
            int w=e.second;

            if(w <= X){
                if(dp[v] > dp[u] + 1){
                    dp[v] = dp[u] + 1;
                    par[v] = u;
                }
            }
        }
    }

    return dp[n] <= d;
}

vector<int> build_path(int X){
    vector<int> dp(n+1,1e18);
    vector<int> par(n+1,-1);
    dp[1]=0;
    for(int u=1;u<=n;u++){
        if(dp[u] > d) continue;
        for(auto &e:adj[u]){
            int v=e.first;
            int w=e.second;
            if(w <= X){
                if(dp[v] > dp[u] + 1){
                    dp[v] = dp[u] + 1;
                    par[v] = u;
                }
            }
        }
    }
    vector<int> path;
    if(dp[n] > d) return path;
    int cur=n;
    while(cur!=-1){
        path.push_back(cur);
        cur=par[cur];
    }
    reverse(all(path));
    return path;
}

void solve(){
    cin>>n>>m>>d;
    adj.assign(n+1,{});
    edges.resize(m);
    int lo=1e18, hi=0;
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        adj[edges[i].u].push_back({edges[i].v,edges[i].w});
        lo=min(lo,edges[i].w);
        hi=max(hi,edges[i].w);
    }
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(feasible(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    if(ans==-1){
        cout<<-1<<"\n";
        return;
    }
    vector<int> path = build_path(ans);
    cout<<path.size()-1<<"\n";
    for(int x:path) cout<<x<<" ";
    cout<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}