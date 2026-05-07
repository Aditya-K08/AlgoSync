#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    bool odd=false,even=false;
    int a[n];
    for (int i=0,x;i<n;++i) {
        cin>>a[i];
        if(!(a[i]&1)) even=true;
        else odd=true;
    }
    if(odd && even) sort(a,a+n);
    for (int i=0;i<n;++i) cout<<a[i]<<" \n";
    cout<<"\n";
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