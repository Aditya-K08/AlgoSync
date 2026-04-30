#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<vector<int>>temp(4);
    for(int i=0;i<n;i++){
        if(arr[i]%6==0){
            temp[0].push_back(arr[i]);
        }else if(arr[i]%2==0){
            temp[1].push_back(arr[i]);
        }else if(arr[i]%3==0){
            temp[2].push_back(arr[i]);
        }else{
            temp[3].push_back(arr[i]);
        }
    }
    vector<int>res;
    for(auto x:temp[0]){
        res.push_back(x);
    }
    for(auto x:temp[1]){
        res.push_back(x);
    }
    for(auto x:temp[3]){
        res.push_back(x);
    }
    for(auto x:temp[2]){
        res.push_back(x);
    }
    for(auto x:res) cout<<x<<" ";
    cout<<"\n";
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