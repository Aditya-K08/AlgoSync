#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int valleys=0;
    int i=0;
    while(i<n) {
        int st=i;
        int val=arr[i];
        while(i<n && arr[i]==val){
            i++;
        }
        int ed=i-1;
        bool left=(st==0) || (arr[st-1]>val);
        bool right=(ed==n-1) || (val<arr[ed+1]);
        if (left && right) {
              valleys++;
            }
    }
    cout<<(valleys==1 ? "YES" : "NO") << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}