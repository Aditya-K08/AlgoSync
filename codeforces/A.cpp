#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>pos(n+1);
    for(int i=0;i<n;i++){
        pos[arr[i]]=i+1;
    }
    for(int i=1;i<=n;i++) cout<<pos[i]<<" ";
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}