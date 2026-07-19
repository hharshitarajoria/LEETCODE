class Solution {
public:
    int countSubarrays(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int sum=0;
        int l=0;
        int r=0;
        int cnt=0;
        int len=0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){
                sum = sum-nums[l];
                l++;
            }
            len= r-l+1;
            cnt += len;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return  countSubarrays(nums,goal) -  countSubarrays(nums,goal-1); 
    }
};