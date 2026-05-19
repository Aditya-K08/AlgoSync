#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int mn=*min_element(arr.begin(),arr.end());
    int sum=0;
    for(int x:arr) sum+=(x-mn);
    cout<<sum<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}