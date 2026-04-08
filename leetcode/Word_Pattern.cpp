class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> arr;
        string word;

        while(ss >> word) arr.push_back(word);
        if(pattern.size() != arr.size()) return false;

        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;

        for(int i = 0; i < pattern.size(); i++){
            if(mp1[pattern[i]] != mp2[arr[i]]) return false;
            mp1[pattern[i]] = mp2[arr[i]] = i + 1;
        }
        return true;
    }
};