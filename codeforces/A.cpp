#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="Tetrahedron") ans+=4;
        if(s=="Cube") ans+=6;
        if(s=="Octahedron") ans+=8;
        if(s=="Dodecahedron") ans+=12;
        if(s=="Icosahedron") ans+=20;
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}