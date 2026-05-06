#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()

int n,d;
vector<int>a;

pair<int,int> check(double x){
    vector<double> p(n+1,0);
    for(int i=0;i<n;i++){
        p[i+1] = p[i] + (a[i] - x);
    }
    double mn = 0;
    int pos = 0;
    for(int r=d;r<=n;r++){
        if(p[r-d] < mn){
            mn = p[r-d];
            pos = r-d;
        }
        if(p[r] - mn >= 0){
            return {pos+1, r}; 
        }
    }
    return {-1,-1};
}

void solve(){
    cin>>n>>d;
    a.resize(n);
    for(auto &x:a) cin>>x;
    double lo = 0, hi = 100;
    pair<int,int> ans = {1,d};
    for(int i=0;i<100;i++){
        double mid = (lo+hi)/2;
        auto res = check(mid);
        if(res.first != -1){
            lo = mid;
            ans = res;
        }else{
            hi = mid;
        }
    }
    cout<<ans.first<<" "<<ans.second<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}