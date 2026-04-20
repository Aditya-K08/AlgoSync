#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;

    int i=0, cnt=0, ans=0;

    while(i<n){
        if(arr[i]==0){
            cnt++;
            if(cnt==k){
                ans++;
                cnt=0;
                i++;
            }
        }else{
            cnt=0;
        }
        i++;
    }

    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}