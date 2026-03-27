#include<bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree{
public:
    int n;
    vector<pair<int,int>>tree;

    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
    }

    pair<int,int> merge(pair<int,int>a,pair<int,int>b){
        if(a.first < b.first) return a;
        if(b.first < a.first) return b;
        return {a.first, a.second + b.second};
    }

    void build(int idx,int l,int r,vector<int>&arr){
        if(l==r){
            tree[idx]={arr[l],1};
            return;
        }
        int mid=l+(r-l)/2;
        build(2*idx,l,mid,arr);
        build(2*idx+1,mid+1,r,arr);
        tree[idx]=merge(tree[2*idx],tree[2*idx+1]);
    }

    pair<int,int> query(int idx,int l,int r,int left,int right){
        if(r<left || right<l) return {LLONG_MAX,0};
        if(l>=left && r<=right) return tree[idx];
        int mid=l+(r-l)/2;
        auto leftVal=query(2*idx,l,mid,left,right);
        auto rightVal=query(2*idx+1,mid+1,r,left,right);
        return merge(leftVal,rightVal);
    }

    void update(int idx,int l,int r,int node ,int val){
        if(l==r){
            tree[idx]={val,1};
            return;
        }
        int mid=l+(r-l)/2;
        if(node<=mid){
            update(2*idx,l,mid,node,val);
        }else{
            update(2*idx+1,mid+1,r,node,val);
        }
        tree[idx]=merge(tree[2*idx],tree[2*idx+1]);
    }
};

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;

    SegmentTree Sgt(arr);
    Sgt.build(1,0,n-1,arr);

    for(int i=1;i<=q;i++){
        int idx,l,r;
        cin>>idx>>l>>r;
        if(idx==2){
            auto res=Sgt.query(1,0,n-1,l,r-1);
            cout<<res.first<<" "<<res.second<<endl;
        }
        else{
            Sgt.update(1,0,n-1,l,r);
        }
    }
    return 0;
}