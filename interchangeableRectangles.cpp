class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n =rectangles.size();
        long long count=0;
        unordered_map<double, int>mp;
        for(int i=0; i<n; i++){
            double ratio = double(rectangles[i][0])/double(rectangles[i][1]);
            if(mp.find(ratio)!=mp.end()){
                count+=mp[ratio];
            }
            mp[ratio]++;
        }
        return count;
    }
};
