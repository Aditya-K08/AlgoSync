#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a) cin>>x;
    int g=a[0];
    for(int i=1;i<n;i++) g=__gcd(g,a[i]);
    if(g!=1){
        cout<<-1;
        return 0;
    }
    int ones=count(a.begin(),a.end(),1);
    if(ones>0){
        cout<<n-ones;
        return 0;
    }
    int min_len=1e18;
    for(int i=0;i<n;i++){
        int g=0;
        for(int j=i;j<n;j++){
            g=__gcd(g,a[j]);
            if(g==1){
                min_len=min(min_len,j-i+1);
                break;
            }
        }
    }
    cout<<min_len + n - 2;
}