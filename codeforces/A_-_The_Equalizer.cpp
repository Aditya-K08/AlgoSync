#include<bits/stdc++.h>
#include <numeric>
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
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;
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
const int MAXN = 100005;

int treePar[MAXN],bcc[MAXN],dep[MAXN];
int bridges=0;

int find(int x){
    return bcc[x]==x?x:bcc[x]=find(bcc[x]);
}

int lca(int u,int v){
    while(true){
        int a=find(u),b=find(v);
        if(a==b) return a;
        if(dep[a]>dep[b]) u=treePar[a];
        else v=treePar[b];
    }
}

void contract(int u,int top){
    while(find(u)!=find(top)){
        int f=find(u);
        int p=find(treePar[f]);
        bcc[f]=p;
        bridges--;
        u=p;
    }
}

int treeRoot(int u){
    while(treePar[find(u)]!=0) u=treePar[find(u)];
    return find(u);
}

void addEdge(int u,int v){
    u=find(u),v=find(v);
    if(u==v) return;

    if(treeRoot(u)!=treeRoot(v)){
        bridges++;
        treePar[u]=v;
        dep[u]=dep[v]+1;
    }else{
        int l=lca(u,v);
        contract(u,l);
        contract(v,l);
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int sum=accumulate(arr.begin(),arr.end(),0);
    int nsum=k*n;
    if(sum&1 || !(nsum&1)){
        pyes;
    }else{
        pno;
    }


}

int32_t main(){
#ifdef Zenith08
    freopen("Error.txt","w",stderr);
    // freopen("connect.in","r",stdin);
    // freopen("connect.out","w",stdout);
#endif    

    fastio();

    auto start=chrono::high_resolution_clock::now();

    int t=1;
    cin>>t;
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