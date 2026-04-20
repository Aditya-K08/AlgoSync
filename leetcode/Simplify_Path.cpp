class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();

        for(int i = 0; i < n; i++){
            if(path[i] == '/'){
                continue; 
            }
            else if(path[i] == '.'){
                string str = ".";
                while(i+1 < n && path[i+1] == '.'){
                    str += ".";
                    i++;
                }
                if(i+1 < n && path[i+1] != '/'){
                    string name = str;
                    i++;
                    while(i < n && path[i] != '/'){
                        name += path[i];
                        i++;
                    }
                    i--;
                    st.push(name);
                }
                else if(str == ".."){
                    if(!st.empty()) st.pop();
                }
                else if(str == "."){
                    continue;
                }
                else{
                    st.push(str);
                }
            }
            else{
                string str = "";
                while(i < n && path[i] != '/'){
                    str += path[i];
                    i++;
                }
                i--;
                st.push(str);
            }
        }

        vector<string> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        string res = "";
        for(auto &s : temp){
            res += "/" + s;
        }

        return res.empty() ? "/" : res;
    }
};