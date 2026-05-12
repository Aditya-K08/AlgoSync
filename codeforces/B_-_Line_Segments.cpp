#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int px,py,qx,qy;
    cin>>px>>py>>qx>>qy;
    vector<int>a(n);
    int sum=0,mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    int mn=max(0LL,2*mx-sum);
    int dx=qx-px;
    int dy=qy-py;
    int d2=1LL*dx*dx + 1LL*dy*dy;
    if(1LL*mn*mn<=d2 && d2<=1LL*sum*sum)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}