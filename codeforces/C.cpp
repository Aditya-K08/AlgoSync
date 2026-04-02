#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;

    vector<long long>pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+arr[i-1];
    }

    long long sum=pref[n];
    if(sum%3){
        cout<<0<<endl;
        return;
    }

    long long t1=sum/3;
    long long t2=2*sum/3;

    vector<int>cnt(n+1,0);

    for(int i=n;i>=1;i--){
        cnt[i]=cnt[i+1];
        if(pref[i]==t2) cnt[i]++;
    }

    long long ans=0;
    for(int i=1;i<=n-2;i++){
        if(pref[i]==t1){
            ans+=cnt[i+1];
        }
    }

    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}