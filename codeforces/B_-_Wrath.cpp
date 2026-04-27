#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int low=INT_MAX;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        if(i<low){
            cnt++;
            low=i-arr[i];
        }
        else{
            if(i-arr[i]<low) low=i-arr[i];
        }
    }
    cout<<cnt;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}