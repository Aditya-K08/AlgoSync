#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int mn=arr[0];
    for(int x:arr){
        if(x>=2*mn){
            cout<<"NO\n";
            return;
        }
        mn=min(mn,x);
    }
    cout<<"YES\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}