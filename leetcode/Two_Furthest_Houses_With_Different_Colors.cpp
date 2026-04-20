class Solution {
public:
    int maxDistance(vector<int>& arr) {
        int maxi=INT_MIN;
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]!=arr[j]){
                maxi=max(maxi,j-i);
            }
            j--;
        }
        j=n-1,i=0;
        while(j>i){
            if(arr[i]!=arr[j]){
                maxi=max(maxi,j-i);
            }
            i++;
        }
        return maxi;
    }
};