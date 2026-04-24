#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    string res="";
    if(n==m){
        res=string(n,'a');
        cout<<res<<endl;
        return ;
    }
    int rem=n-m;
    res=string(m,'a');
    vector<char>arr={'c','b','a'};
    int idx=0;
    for(int i=0;i<rem;i++){
        res+=arr[(idx++)%3];
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}