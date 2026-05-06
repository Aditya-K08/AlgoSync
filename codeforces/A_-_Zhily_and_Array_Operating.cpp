#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

int n,d;
void solve(){
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;

    int cnt=(arr[n-1]>0);
    for(int i=n-2;i>=0;i--){
        if(arr[i]>0){
            if(arr[i+1]>0){
                arr[i]+=arr[i+1];
            }
            cnt++;
        }else{
            if((arr[i]+arr[i+1])>0){
                arr[i]+=arr[i+1];
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}