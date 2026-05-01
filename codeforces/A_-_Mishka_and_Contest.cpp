#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int i=0;
    int cnt=0;
    for(i;i<n;i++){
        if(arr[i]<=k) cnt++;
        else break;
    }
    for(int j=n-1;j>=i;j--){
        if(arr[j]<=k) cnt++;
        else break;
    }
    cout<<cnt<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}