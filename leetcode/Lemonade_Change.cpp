class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a1=0,a2=0,a3=0;
        for(int x:bills){
            if(x==5) a1++;
            else if(x==10){
                if(a1) 
                {a1--;
                a2++;
                }
                else return false;
            }
            else if(x==20){
                if(a1 && a2){
                    a1--;
                    a2--;
                }else if(a1>=3){
                    a1-=3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};