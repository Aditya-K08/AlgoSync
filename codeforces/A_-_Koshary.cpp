#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x,y;
    cin>>x>>y;
    cout<<((x%2==1 && y%2==1) ? "NO\n" : "YES\n");
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}