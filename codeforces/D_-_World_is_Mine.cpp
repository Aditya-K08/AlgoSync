#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int maxKills(const vector<int>& b){
    priority_queue<int> pq;
    ll total=0;
    for(int i=0;i<(int)b.size();i++){
        int p=b[i]+1;
        total+=p;
        pq.push(p);
        int deadline=i+2;
        if(total>deadline){
            total-=pq.top();
            pq.pop();
        }
    }
    return (int)pq.size();
}

int solve(int n,const vector<int>& a){
    vector<int> freq(n+1,0);
    for(int x:a) freq[x]++;

    vector<int> cnt;
    for(int v=1;v<=n;v++) if(freq[v]>0) cnt.push_back(freq[v]);

    int M=(int)cnt.size(),best=0;

    for(int s=0;s<M;s++){
        int suffixLen=M-s-1;
        int aliceMoves;

        if(suffixLen==0) aliceMoves=1;
        else{
            vector<int> b;
            b.reserve(suffixLen);
            for(int j=s+1;j<M;j++) b.push_back(cnt[j]);
            int kills=maxKills(b);
            aliceMoves=(M-s)-kills;
        }

        best=max(best,aliceMoves);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<solve(n,a)<<"\n";
    }
    return 0;
}