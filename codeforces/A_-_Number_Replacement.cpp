#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    unordered_map<int,char>map;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(!map.count(arr[i])){
            map[arr[i]]=s[i];
        }else{
            if(map[arr[i]]!=s[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}