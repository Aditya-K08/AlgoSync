// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n&1){
        cout<<0<<endl;
        return;
    }
    int x=n/4;
    int y=n%4;
    if(y==0){
        cout<<x<<endl;
    }else{
        cout<<x+y/2<<endl;
    }
}
int main() {
	int t;
    cin>>t;
    while(t--) solve();
    return 0;
}