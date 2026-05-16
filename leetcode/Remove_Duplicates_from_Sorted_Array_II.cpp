class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int len=0;
        while(j<n){
            int val=nums[j];
            int cnt=0;
            while(j<n && nums[j]==val){
                cnt++;
                j++;
            }
            if(cnt>=2){
                nums[i++]=val;
                nums[i++]=val;
                len+=2;
            }else{
                nums[i++]=val;
                len++;
            }
        }
        return len;
    }
};