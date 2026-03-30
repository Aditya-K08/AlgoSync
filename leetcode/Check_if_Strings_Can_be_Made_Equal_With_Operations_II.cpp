class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int>eve(26,0),odd(26,0);
        for(int i=0;i<n;i+=2){
            eve[s1[i]-'a']++;
            eve[s2[i]-'a']--;
        }
        for(int i=1;i<n;i+=2){
            odd[s1[i]-'a']++;
            odd[s2[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(eve[i] || odd[i]) return false;
        }
        return true;
    }
};