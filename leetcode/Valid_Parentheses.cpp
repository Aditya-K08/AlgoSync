class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        if(n&1) return false;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                else{
                    char c=st.top();
                    st.pop();
                    if(s[i]==')' && c!='(') return false;
                    if(s[i]=='}' && c!='{') return false;
                    if(s[i]==']' && c!='[') return false;
                 }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};