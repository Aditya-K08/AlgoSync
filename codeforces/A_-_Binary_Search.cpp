#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n";
#define all(x) x.begin(),x.end()

bool binarysearch(vector<int>arr,int x){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x) return true;
        if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    return false;
}
void solve(){
    int n,q; 
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(binarysearch(arr,x)){
            pyes;
        }else{
            pno;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1; 
    //cin>>t;
    while(t--) solve();
}