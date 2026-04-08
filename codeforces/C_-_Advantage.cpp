#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int mx=*max_element(arr.begin(),arr.end());
    int cnt=0;
    int sec=INT_MIN;
    for(int x:arr){
        if(x==mx) cnt++;
        if(x<mx){
            sec=max(sec,x);
        }
    }
    if(cnt>=2) sec=mx;
    for(int x:arr){
        if(x==mx) cout<<mx-sec<<" ";
        else cout<<x-mx<<" ";
    } 
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}