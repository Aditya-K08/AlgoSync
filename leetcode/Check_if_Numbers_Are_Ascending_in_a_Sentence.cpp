class Solution {
public:
    bool isNumber(const string &s){
        for(char c : s){
            if(!isdigit(c)) return false;
        }
        return true;
    }

    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string word;
        int prev = -1;

        while(ss >> word){
            if(isNumber(word)){
                int num = stoi(word);
                if(num <= prev) return false;
                prev = num;
            }
        }
        return true;
    }
};