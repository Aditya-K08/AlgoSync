#include<bits/stdc++.h>
using namespace std;
const int N = 300009;
int n,k,t,a[N],tt[N];
long long b[N],ans[N],sum,mxa;
struct FLONG{
	long long val;
	int nd;
	FLONG(long long v = 0,int d = 0):
		val(v),nd(d)
	{}
	bool operator<(const FLONG &b)const{
		return val > b.val || (val == b.val && nd < b.nd);
	}
};
set<FLONG>s;
set<FLONG> :: iterator o;
struct pir{
	int to,len;
	pir(int t = 0,int l = 0):
		to(t),len(l)
	{}
	bool operator<(const pir &b)const{
		return len > b.len || (len == b.len && to < b.to);
	}
}mn[N],se[N],lf[N];
vector<int>e[N];
void srh(int v,int fa){
	mn[v] = pir(v,0);
	se[v] = pir(0,~0x3f3f3f3f);
	lf[v] = pir(0,~0x3f3f3f3f);
	for(unsigned i = 0; i < e[v].size(); i ++){
		if(e[v][i] != fa){
			srh(e[v][i],v);
			pir th = mn[e[v][i]];
			th.len ++;
			if(th < se[v])
				swap(th,se[v]);
			if(se[v] < mn[v])
				swap(se[v],mn[v]);
		}
	}
}
void gt1(){
	sum = ans[1] = 0;
	ans[1] += a[1];
	for(int i = 2; i <= n; i ++){
		b[mn[i].to] += a[i];
		tt[i] = mn[i].to;
		//printf("%d %d\n",i,tt[i]);
	}
	s.clear();
	for(int i = 2; i <= n; i ++){
		s.insert(FLONG(b[i],i));
	}
	o = s.begin();
	ans[1] += o -> val;
	sum += o -> val;
	for(int i = 1; i < k - 1; i ++){
		o ++;
		ans[1] += o -> val;
		sum += o -> val;
	}
	s.insert(FLONG(-1ll,0));
	s.insert(FLONG(-2ll,0));
}
void era(int x){
	FLONG u = FLONG(b[x],x);
	if(!(*o < u)){
		o ++;
		sum += o -> val;
		sum -= b[x];
	}
	s.erase(u);
	//printf("%d %lld\n",x,sum);
}
void ins(int x){
	FLONG u = FLONG(b[x],x);
	s.insert(u);
	if(!(*o < u)){
		sum -= o -> val;
		sum += b[x];
		o --;
	}
	//printf("%d %lld\n",x,sum);
}
void stp(int x){
	era(tt[x]);
	b[tt[x]] -= a[x];
	ins(tt[x]);
	tt[x] = 0; 
}
void sett(int x,int ttp){
	tt[x] = ttp;
	era(tt[x]);
	b[tt[x]] += a[x];
	ins(tt[x]);
}
void srho(int v,int fa){
	//printf(" %d %d\n",v,fa);
	if(fa != 0){
		stp(v);
		era(v);
		ins(fa);
		sett(fa,lf[fa].to);
		ans[v] = sum + a[v];
	}
	for(unsigned i = 0; i < e[v].size(); i ++){
		if(e[v][i] != fa){
			pir u = lf[fa];
			u.len ++;
			if(mn[v].to == mn[e[v][i]].to)
				lf[v] = min(u,se[v]);
			else
				lf[v] = min(u,mn[v]);
			srho(e[v][i],v);
		}
	}
	if(fa != 0){
		ins(v);
		sett(v,mn[v].to);
		stp(fa);
		era(fa);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		mxa = 0;
		for(int i = 1; i <= n; i ++){
			scanf("%d",&a[i]);
			mxa = max(mxa,1ll * a[i]);
			e[i].clear();
			b[i] = 0;
		}
		for(int i = 1; i < n; i ++){
			int u,v;
			scanf("%d %d",&u,&v);
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		if(k == 1){
			printf("%lld\n",mxa);
			continue;
		}
		lf[0].len = ~0x3f3f3f3f;
		srh(1,0);
		gt1();
		srho(1,0);
		for(int i = 1; i <= n; i ++){
			mxa = max(mxa,ans[i]);
			//printf("%lld\n",ans[i]);
		}
		printf("%lld\n",mxa);
	}
}