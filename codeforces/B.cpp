#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
#define int long long

int mod=32768;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;

    for(int x:arr){
        queue<pair<int,int>>q;
        vector<int>vis(mod,0);
        q.push({x,0});
        vis[x]=1;
        while(!q.empty()){
            auto [u,d]=q.front();
            q.pop();
            if(u==0){
                cout<<d<<" ";
                break;
            }
            int v1=(u+1)%mod;
            int v2=(u*2)%mod;
            if(!vis[v1]){
                vis[v1]=1;
                q.push({v1,d+1});
            }
            if(!vis[v2]){
                vis[v2]=1;
                q.push({v2,d+1});
            }
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}