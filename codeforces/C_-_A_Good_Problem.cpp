#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    if(n&1){
        cout<<l<<"\n";
        return;
    }
    if(n==2){
        cout<<-1<<"\n";
        return;
    }
    int x=1;
    while(x<=l) x<<=1;
    if(x>r){
        cout<<-1<<"\n";
        return;
    }
    if(k<=n-2) cout<<l<<"\n";
    else cout<<x<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}