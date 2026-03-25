class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> pref(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j] =grid[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
        long long total=pref[n][m];
        for(int i=1;i<n;i++){
            if(2*pref[i][m]==total) return true;
        }
        for(int j=1;j<m;j++){
            if(2*pref[n][j]==total) return true;
        }
        return false;
    }
};