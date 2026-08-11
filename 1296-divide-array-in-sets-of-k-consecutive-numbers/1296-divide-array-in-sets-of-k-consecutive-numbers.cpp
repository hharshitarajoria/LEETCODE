class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n= nums.size();
        if(n%k != 0) return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(auto x: nums){
            mpp[x]++;
        }
        for(auto x: nums){
            if(mpp[x]==0) continue;
            for(int i=0; i<k;i++){
                if(mpp[x+i]==0) return false;

                mpp[x+i]--;
            }
        }
        return true;
    }
};