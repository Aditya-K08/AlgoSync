#include<bits/stdc++.h>
#include <numeric>
using namespace std;
using namespace chrono;
/*
    In The Name of God :)
*/
#define Zenith08
#define all(x) x.begin(),x.end()
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i,st,n) for(int i=st;i<n;i++)
#define rev(i,n,st) for(int i=n;i>=0;i--)
#define nline cout<<"\n"
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;
#define int long long
using p=pair<int,int>;



void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int cnt=0,ans=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]< 2*arr[i+1]) cnt++;
        else cnt=0;
        if(cnt>=k) ans++;
    }
    cout<<ans<<"\n";
}

int32_t main(){
#ifdef Zenith08
    freopen("Error.txt","w",stderr);
    // freopen("connect.in","r",stdin);
    // freopen("connect.out","w",stdout);
#endif    

    fastio();

    auto start=chrono::high_resolution_clock::now();

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    auto stop=chrono::high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
#ifdef Zenith08
    cerr<<"Time:"<<duration.count()/1000<<" ms"<<endl;
#endif

    return 0;
}