class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
         // Sort by ending time
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int cnt = 0;
        int end = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] < end){
                cnt++;
            }
            else{
                end= intervals[i][1];;
            }
        }
        return cnt;
    }
};