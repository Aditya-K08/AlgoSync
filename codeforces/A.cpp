#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int mx=*max_element(arr.begin(),arr.end());
    int mn=*min_element(arr.begin(),arr.end());
    int st=-1,ed=-1;
    for(int i=0;i<n;i++){
        if(mx==arr[i] && st==-1){
            st=i;
        }
        if(mn==arr[i]){
            ed=i;
        }
    }
    int ans;
    if(st<ed){
        cout<<st+(n-1-ed)<<endl;
    }else{
        cout<<st+(n-1-ed)-1<<endl;
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}