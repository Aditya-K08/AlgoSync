#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        int x=arr[i];
        for(int j=i+1;j<n;j++){
            int y=arr[j];
            if((x&y)==0){
                ans[i]=y;
                ans[j]=x;
                break;
            }
        }
   }
   for(int x:ans) cout<<x<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}