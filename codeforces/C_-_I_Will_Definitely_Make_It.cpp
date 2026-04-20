#include<bits/stdc++.h>
using namespace std;
#define pyes cout<<"Yes"<<endl
#define pno cout<<"No"<<endl
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int curr=arr[k-1];
    int mx=arr[k-1];
    sort(arr.begin(),arr.end());
    for(int x:arr){
        if(x>curr && x-curr>mx){
            pno;
            return;
        }
        curr=x;
    }
    pyes;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}