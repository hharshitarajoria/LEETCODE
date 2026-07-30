class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        map<int,int> mpp;
        mpp[0]=1; 
        int prefixsum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            prefixsum += nums[i];
            int remaining = prefixsum - k;
            cnt +=  mpp[remaining];
            mpp[prefixsum]+=1;
        }
        return cnt;
    }
};