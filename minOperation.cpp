class Solution {
public:
    int minOperations(vector<string>& logs) {
        int awayFromMain=0;
        int n = logs.size();
        for(int i=0; i<n; i++){
            if(logs[i]== "../") {
                if(awayFromMain>0)awayFromMain--;
                }
            else if(logs[i]=="./") continue;
            else awayFromMain++;
        }
        return awayFromMain;
    }
};
