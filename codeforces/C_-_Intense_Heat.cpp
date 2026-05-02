#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, int k, double mid){
    int n = a.size();
    vector<double> pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + (a[i] - mid);
    }
    double min_pref = 0;
    for(int i=k;i<=n;i++){
        if(pref[i] - min_pref >= 0) return true;
        min_pref = min(min_pref, pref[i-k+1]);
    }
    return false;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &x:a) cin>>x;
    double l = *min_element(a.begin(),a.end());
    double r = *max_element(a.begin(),a.end());
    for(int it=0; it<100; it++){
        double mid = (l+r)/2;
        if(check(a,k,mid)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(12)<<l<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}