class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n= nums.size();
        if(n%k != 0) return false;
        priority_queue<int, vector<int> , greater<int>> pq;
        map<int,int> mpp;
        for(auto x: nums){
            mpp[x]++;
            pq.push(x);
        }
        while(!pq.empty()){
            int first= pq.top();
            pq.pop();
            if(mpp[first]==0) continue;
            for(int i=0; i<k;i++){
                if(mpp[first+i]==0) return false;

                mpp[first+i]--;
            }
        }
        return true;
    }
};