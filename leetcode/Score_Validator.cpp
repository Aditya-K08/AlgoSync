class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int cnt=0,sum=0;
        for(int i=0;cnt<10 && i<events.size();i++){
            string str=events[i];
            if(str=="W") cnt++;
            else if(str=="WD" || str=="NB") sum++;
            else sum+=stoi(str);
        }
        return {sum,cnt};
    }
};