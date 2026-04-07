#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
/*
    In The Name of God :)
*/
#define Zenith08
#define all(x) x.begin(),x.end()
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i,st,n) for(int i=st;i<n;i++)
#define rev(i,n,st) for(int i=n;i>=0;i--)
#define nline cout<<"\n"
using p=pair<int,int>;

void input(vector<int>&arr){
    for(auto &x:arr) cin>>x;
}
void debug(vector<int>arr){
    for(int x:arr) cout<<x<<" ";
}
/*
5
1
1
2
*/

// struct DSU{
//     int n;
//     vector<int>parent,sz;
//     DSU(int n) : n(n),parent(n),sz(n,1){
//         iota(parent.begin(),parent.end(),0);
//     }
//     int find(int x){
//         if(x!=parent[x]){
//             parent[x]=find(parent[x]);
//         }
//         return parent[x];
//     }
//     void unite(int u,int v){
//         u=find(u);
//         v=find(v);
//         if(u==v) return;
//         if(sz[u]<sz[v]) swap(u,v);
//         parent[v]=u;
//         sz[u]+=sz[v];
//     }
// };

struct DSU{
    int n,comps;
    vector<int>parent,rankv;
    stack<array<int,4>>st;

    DSU(int n): n(n),parent(n),rankv(n,0),comps(n){
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        while(x!=parent[x]) x=parent[x];
        return x;
    }
    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v){
            st.push({-1,-1,-1,-1});
            return;
        }
        if(rankv[u]<rankv[v]) swap(u,v);
        st.push({v,parent[v],u,rankv[u]});
        parent[v]=u;
        if(rankv[u]==rankv[v]) rankv[u]++;
        comps--;
    }

    int sz() {return (int)st.size();}
    void rollback(int cnt){
        while(st.size()>cnt){
            auto[v,par,u,rnk]=st.top();
            st.pop();
            if(v==-1) continue;
            parent[v]=par;
            rankv[u]=rnk;
            comps++;
        }
    }
};
using p=pair<int,int>;
vector<vector<p>>tree;

void add(int node,int l,int r,int ql,int qr,p e){
    if(r<ql || qr<l) return;
    if(ql<=l && r<=qr){
        tree[node].push_back(e);
        return;
    }
    int mid=l+(r-l)/2;
    add(2*node,l,mid,ql,qr,e);
    add(2*node+1,mid+1,r,ql,qr,e);
}

vector<int>ans;
void dfs(int node,int l,int r,DSU &dsu){
    if(l>r) return;
    int sz=dsu.sz();
    for(auto [u,v]:tree[node]) dsu.unite(u,v);
    if(l==r) {
        ans.push_back(dsu.comps);
    }else{
        int mid=l+(r-l)/2;
        dfs(2*node,l,mid,dsu);
        dfs(2*node+1,mid+1,r,dsu);
    }
    dsu.rollback(sz);
}

void solve(){
    int n,q;
    cin>>n>>q;
    tree.clear();
    ans.clear();
    map<p,int>start;
    vector<array<int,4>>adj;
    int cnt=0;
    for(int i=0;i<q;i++){
        char type;
        cin>>type;
        if(type=='?'){
            cnt++;
        }else{
            int u,v;
            cin>>u>>v;
            u--,v--;
            if(u>v) swap(u,v);
            if(type=='+'){
                start[{u,v}]=cnt;
            }else{
                int l=start[{u,v}];
                int r=cnt-1;
                if(l<=r) adj.push_back({l,r,u,v});
                start.erase({u,v});
            }
        }
    }

    for(auto &[e,ct]:start){
        int ed=cnt-1;
        adj.push_back({ct,ed,e.first,e.second});
    }

    if(cnt>0){
        tree.resize(4*cnt+5);

        for(auto [l,r,u,v]:adj){
            add(1,0,cnt-1,l,r,{u,v});
        }
        DSU dsu(n);
        dfs(1,0,cnt-1,dsu);
    }

    for(int x:ans) cout<<x<<"\n";
}

int32_t main(){
#ifdef Zenith08
    freopen("Error.txt","w",stderr);
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
#endif    

    fastio();

    auto start=chrono::high_resolution_clock::now();

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    auto stop=chrono::high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
#ifdef Zenith08
    cerr<<"Time:"<<duration.count()/1000<<" ms"<<endl;
#endif

    return 0;
}