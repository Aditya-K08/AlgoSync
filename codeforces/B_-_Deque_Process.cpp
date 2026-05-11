#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    string res="";
    bool flag=true;
    int l=0,r=n-1;
    while(l<=r){
        if(flag){
            if(arr[l]<arr[r]){
                res.push_back('L');
                l++;
            }else{
                res.push_back('R');
                r--;
            }
        }else{
            if(arr[l]>arr[r]){
                res.push_back('L');
                l++;
            }else{
                res.push_back('R');
                r--;
            }
        }
        flag=!flag;
    }

    cout<<res<<'\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}