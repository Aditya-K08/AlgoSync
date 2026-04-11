class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string str="";
        while(!pq.empty()){
            auto [len,c]=pq.top();
            pq.pop();
            string st;
            st.assign(len,c);
            cout<<st<<" ";
            str+=st;
        }
        return str;
    }
};