#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<int>arr(7);
    for(auto &x:arr) cin>>x;
    int maxi=*max_element(arr.begin(),arr.end());
    int sum=accumulate(arr.begin(),arr.end(),0);
    int rem=2*maxi-sum;
    cout<<rem<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}