#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,k;
    cin>>n>>k;
    int cnt=__builtin_popcountll(n);
    if(cnt>k || k>n){
        cout<<"NO\n";
        return 0;
    }
    priority_queue<int>pq;
    for(int i=0;i<60;i++){
        if(n&(1LL<<i)){
            pq.push(1LL<<i);
        }
    }
    while(pq.size()<k){
        int x=pq.top(); pq.pop();
        if(x==1) break;
        pq.push(x/2);
        pq.push(x/2);
    }
    if(pq.size()!=k){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}