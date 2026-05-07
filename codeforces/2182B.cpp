#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b;
    cin>>a>>b;
    if(a<b) swap(a,b);
    int x=0,y=0;
    int ans=0;
    int cur=1;
    while(1){
        int nx=y+cur;
        int ny=x;
        if(nx<=a && ny<=b){
            ans++;
            x=nx;
            y=ny;
            cur*=2;
        }else{
            break;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}