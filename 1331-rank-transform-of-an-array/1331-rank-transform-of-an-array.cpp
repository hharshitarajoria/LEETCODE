class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            //{value,originalindex}
            pq.push({arr[i],i});
        }
        vector<int> ans(n);
        int rank=0;
        int prev = INT_MAX;
        while(!pq.empty()) {
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            // Increase rank only for a new value
            if(value != prev) {
                rank++;
                prev = value;
            }
            ans[index] = rank;
        }
        return ans;
    }
};