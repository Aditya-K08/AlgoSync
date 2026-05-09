#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    sort(allr(arr));
    int sum=0;
    for(int i=0;i<n;i+=2){
        sum+=arr[i];
    }
    cout<<sum<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}