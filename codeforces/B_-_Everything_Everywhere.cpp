#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int cnt=0;
    for(int i=1;i<n;i++){
        int g=gcd(arr[i-1],arr[i]);
        int mx=max(arr[i-1],arr[i]);
        int mn=min(arr[i-1],arr[i]);
        if(g==(mx-mn)) cnt++;
    }
    cout<<cnt<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}