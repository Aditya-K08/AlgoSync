#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> getDiv(int n){
    vector<int> d;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i*i!=n) d.push_back(n/i);
        }
    }
    return d;
}

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> da=getDiv(a);
    vector<int> db=getDiv(b);
    int k=a*b;
    for(int i=0;i<da.size();i++){
        for(int j=0;j<db.size();j++){
            int g=da[i]*db[j];

            int x=((a/g)+1)*g;
            int need=k/g;
            int y=((b/need)+1)*need;

            if(x<=c && y<=d){
                cout<<x<<" "<<y<<endl;
                return;
            }
        }
    }

    cout<<-1<<" "<<-1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}