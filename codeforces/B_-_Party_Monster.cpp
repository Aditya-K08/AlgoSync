#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1){
        cout<<"NO\n";
        return;
    }
    int cnt1=count(s.begin(),s.end(),'(');
    int cnt2=n-cnt1;
    if(cnt1==cnt2){
        cout<<"YES\n";
    }else{
        cout<<"No\n";
    }
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