class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        vector<string> ans;
        int n = arr.size();
        for(int i = 0; i < n; ){
            int j = i;
            while(j + 1 < n && arr[j + 1] == arr[j] + 1) j++;
            if(i == j){
                ans.push_back(to_string(arr[i]));
            }else{
                ans.push_back(to_string(arr[i]) + "->" + to_string(arr[j]));
            }
            i = j + 1; 
        }
        return ans;
    }
};