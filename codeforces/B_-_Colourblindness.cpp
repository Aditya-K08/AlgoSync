#include<bits/stdc++.h>
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
using p=pair<int,int>;

void input(vector<int>&arr){
    for(auto &x:arr) cin>>x;
}
void debug(vector<int>arr){
    for(int x:arr) cout<<x<<" ";
}

void solve(){
    int n;
    cin>>n;
    vector<string> arr(2);
    cin>>arr[0];
    cin>>arr[1];

    for(int i=0;i<n;i++){
        if(arr[0][i] != arr[1][i]){
            if((arr[0][i]=='B' && arr[1][i]=='G') || (arr[0][i]=='G' && arr[1][i]=='B')){
                continue; 
            }
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int32_t main(){
#ifdef Zenith08
    freopen("Error.txt","w",stderr);
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