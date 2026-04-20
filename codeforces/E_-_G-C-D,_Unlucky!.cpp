#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;  
    vector<int>a(n);
    vector<int>b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    if(b[0]!=a[n-1]){
        cout<<"NO"<<endl;
        return ;
    }
    vector<int>arr(n);
    bool flag=false;
    for(int i=0;i<n;i++){
        if(i>0 && a[i-1]%a[i]!=0) flag=true;
        if(i<n-1 && b[i+1]%b[i]!=0) flag=true;
        arr[i]=lcm(a[i],b[i]);
    }
    vector<int> pref(n), suff(n);
    pref[0] = arr[0];
    for(int i=1;i<n;i++){
        pref[i] = gcd(pref[i-1], arr[i]);
    }

    suff[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = gcd(suff[i+1], arr[i]);
    }

    for(int i=0;i<n;i++){
        if(pref[i] != a[i] || suff[i] != b[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}