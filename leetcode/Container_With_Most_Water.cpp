class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        long long area=0;
        while(i<j){
            int b=j-i;
            int len=min(height[i],height[j]);
            area=max(area,(long long)len*b);
            if(height[i]<=height[j]){
                i++;
            }else{
                j--;
            }
        }
        return area;
    }
};