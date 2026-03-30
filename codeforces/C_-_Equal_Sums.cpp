#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define vi vector<int>

void solve(){
	int k;
	cin>>k;
	vector<tuple<int,int,int>>a;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		vi arr(n);
		for(auto &x:arr) cin>>x;
		int sum=accumulate(all(arr),0);
		for(int j=0;j<n;j++){
			a.push_back({sum-arr[j],i,j});
		}
	}
	sort(all(a));
	for(int i=0;i<(int)a.size()-1;i++){
		auto [v1,a1,b1]=a[i];
		auto [v2,a2,b2]=a[i+1];
		if(v1==v2 && a1!=a2){
			cout<<"YES\n";
			cout<<a2+1<<" "<<b2+1<<"\n";
			cout<<a1+1<<" "<<b1+1<<"\n";
			return;
		}
	}
	cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}