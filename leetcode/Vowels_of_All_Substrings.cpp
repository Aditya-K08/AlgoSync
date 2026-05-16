class Solution {
public:
    long long countVowels(string word) {
        long long cnt=0;
        string vow="aeiou";
        int n=word.size();
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'){
                cnt+=(long)(n-i)*(long)(i+1);
            }
        }
        return cnt;
    }
};