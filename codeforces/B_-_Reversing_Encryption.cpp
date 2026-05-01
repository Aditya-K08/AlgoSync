#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primes = {
    2,3,5,7,11,13,17,19,23,29,
    31,37,41,43,47
};



void solve(){
    int n;
    cin>>n;
    vector<int>res;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i){
                res.push_back(n/i);
            }
        }
    }
    string s;
    cin>>s;
    sort(res.begin(),res.end());
    for(auto d:res){
        //cout<<d<<" ";
        reverse(s.begin(),s.begin()+d);
    }
    reverse(s.begin(),s.end());
    cout<<s<<" ";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}