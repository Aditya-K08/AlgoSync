#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;

    int total = 0;
    for(char c:a) if(c=='(') total++;
    for(char c:b) if(c=='(') total++;

    if(total != n){
        cout << "NO\n";
        return;
    }
    int mn = 0, mx = 0; 
    int sum = 0; 
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            if(a[i] == '('){
                mn++;
                mx++;
                sum += 2;
            }else{
                mn--;
                mx--;
                sum -= 2;
            }
        }else{
            mn--;
            mx++;
        }
        mn = max(mn, 0LL);
        mx = min(mx, sum);
        int p = (i + 1) & 1;
        if((mn & 1) != p) mn++;
        if((mx & 1) != p) mx--;
        if(mn > mx){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}