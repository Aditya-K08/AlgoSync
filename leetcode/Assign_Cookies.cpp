class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        multiset<int> st(s.begin(),s.end());
        int cnt=0;
        for(int x:g){
            auto it=st.lower_bound(x);
            if(it!=st.end()){
                cnt++;
                st.erase(it);
            }
        }
        return cnt;
    }
};