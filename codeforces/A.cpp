#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<long long>arr(n);
    for(auto &x:arr) cin>>x;

    vector<int>l(m),r(m),d(m);
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>d[i];
    }
    vector<long long>op(m+2,0);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        op[x-1]++;
        op[y]--;
    }

    for(int i=1;i<m;i++){
        op[i]+=op[i-1];
    }

    vector<long long>diff(n+2,0);

    for(int i=0;i<m;i++){
        long long times=op[i];
        if(times==0) continue;

        diff[l[i]-1]+=times*d[i];
        diff[r[i]]-=times*d[i];
    }

    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]+diff[i]<<" ";
    }
    cout<<endl;
}

int main(){
    solve();
    return 0;
}