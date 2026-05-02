#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=count(s.begin(),s.end(),'1');
    if(cnt<=k || n<2*k){
        cout<<"ALice\n";
    }else{
        cout<<"Bob\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}