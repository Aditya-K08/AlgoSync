#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    for(int i=0;i<n;i++){
        cout<<n-arr[i]+1<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}