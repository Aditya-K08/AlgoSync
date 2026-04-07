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
    unordered_map<string,int>mp;
    unordered_map<string,vector<int>>mpp;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            string s;
            cin>>s;
            mp[s]++;
            mpp[s].push_back(i);
        }
    }
    vector<int>ans(3,0);
    for(auto it: mp){
        if(it.second==1){
            int idx=mpp[it.first][0];
            ans[idx]+=3;
        }
        else if(it.second==2){
            for(auto idx:mpp[it.first]){
                ans[idx]+=1;
            }
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
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