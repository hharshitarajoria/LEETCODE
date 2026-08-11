class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize != 0) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int,int> mpp;
        for(int i=0 ;i<n;i++){
            mpp[hand[i]]++;
            pq.push(hand[i]);
        }
        while(!pq.empty()){
            int first=pq.top();
            pq.pop();

            if(mpp[first]==0) continue;

            for(int j=0; j<groupSize;j++){
                if(mpp[first+j]==0) return false;

                mpp[first+j]--;
            }
        }
        return true;
    }
};