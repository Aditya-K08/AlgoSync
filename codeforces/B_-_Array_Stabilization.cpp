#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    if(n==2){
        cout<<0<<endl;
        return 0;
    }
    sort(arr.begin(),arr.end());
    int ans = min({arr[n-2]-arr[0],arr[n-1]-arr[1]});
    cout<<ans<<endl;
    return 0;
}