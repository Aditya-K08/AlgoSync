#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(101,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[x]++;
    }    
    int mx=*max_element(arr.begin(),arr.end());
    cout<<mx<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}