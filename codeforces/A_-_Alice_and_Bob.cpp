#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i,st,n) for(int i=st;i<n;i++)
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
#define pno cout<<"NO"<<endl;
#define pyes cout<<"YES"<<endl;

void solve(){
    int n,a;
    cin>>n>>a;

    vi arr(n);
    rep(i,0,n) cin>>arr[i];
    
    int less = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
    int greater = arr.end() - upper_bound(arr.begin(), arr.end(), a);

        if (greater > less) {
            cout << (a + 1) << '\n';
        } else {
            cout << (a - 1) << '\n';
        }
} 

signed main(){
    int t;
    cin >> t;
    // t=1;
    while (t--) {
        solve();
    }
    return 0;
}