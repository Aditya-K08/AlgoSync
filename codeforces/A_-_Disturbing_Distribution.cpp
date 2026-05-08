#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int sum=0;
    //if(arr[0]!=1) sum=arr[0];
    for(int i=0;i<n;i++){
        if(i>0 && arr[i-1]==1) sum-=1; 
        sum+=arr[i];
    }
    cout<<sum<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}