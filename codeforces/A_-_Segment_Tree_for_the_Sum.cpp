#include<bits/stdc++.h>
using namespace std;
#define int long long
class SegmentTree{
public:
    int n;
    vector<int>tree;
    SegmentTree(vector<int>&arr){
        n=arr.size();
        tree.resize(4*n);
    }

    void build(int idx,int l,int r,vector<int>&arr){
        if(l==r){
            tree[idx]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*idx,l,mid,arr);
        build(2*idx+1,mid+1,r,arr);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
    int query(int idx,int l,int r,int left,int right){
        if(r<left || right<l) return 0;
        if(l>=left && r<=right) return tree[idx];
        int mid =l+(r-l)/2;
        int leftVal=query(2*idx,l,mid,left,right);
        int rightVal=query(2*idx+1,mid+1,r,left,right);
        return leftVal+rightVal;
    }
    void update(int idx,int l,int r,int node ,int val){
        if(l==r){
            tree[idx]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(node<=mid){
            update(2*idx,l,mid,node,val);
        }else{
            update(2*idx+1,mid+1,r,node,val);
        }
        tree[idx]=tree[2*idx+1]+tree[2*idx];
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
        if(idx==2) cout<<Sgt.query(1,0,n-1,l,r-1)<<endl;
        else Sgt.update(1,0,n-1,l,r);
    }
    return 0;
}