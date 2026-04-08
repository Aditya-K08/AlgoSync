class Solution {
public:
    string reverseVowels(string s) {
        set<char>vowels{'a','e','i','o','u','A','E','I','O','U'};
        int n=s.size();
        string v="";
        for(char c:s){
            if(vowels.count(c)) v+=c;
        }
        reverse(v.begin(),v.end());
        cout<<v<<endl;
        int j=0;
        for(int i=0;i<n;i++){
            if(vowels.count(s[i])){
                s[i]=v[j++];
            }
        }
        return s;
    }
};