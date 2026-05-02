#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>mn(n+1,INT_MAX);
    vector<int>mx(n+1,INT_MIN);
    for(int i=0;i<n;i++){
        mn[i+1]=min(mn[i],arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        mx[i]=max(mx[i+1],arr[i]);
    }
    string res="";
    for(int i=0;i<n;i++){
        if(arr[i]==mn[i+1] || arr[i]==mx[i]) res+="1";
        else res+="0";
    }
    cout<<res<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}