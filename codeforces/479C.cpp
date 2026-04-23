// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(auto &x:a) cin>>x.first>>x.second;
    int best = -1;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) {
    if (best<=a[i].second) {
            best=a[i].second;
        } else {
            best = a[i].first;
        }
    }
    cout<<best<<endl;
    return 0;
}