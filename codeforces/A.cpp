#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int left=INT_MAX,right=0;
    vector<pair<int,int>>arr;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        arr.push_back({l,r});
        left=min(l,left);
        right=max(r,right);
    }
    vector<int>pref(right-left+2);
    int prev=0;
    for(int i=left;i<=right;i++){
        int x=__builtin_popcount(i);
        if(prev<x){
            pref[i]=i;
            prev=x;
        }else{
            pref[i]=pref[i-1];
        }
        //cout<<i<<" "<<pref[i]<<"\n";
    }
    for(auto [l,r]:arr){
        cout<<pref[r]<<endl;
    }
}
int main(){
    solve();
    return 0;
}