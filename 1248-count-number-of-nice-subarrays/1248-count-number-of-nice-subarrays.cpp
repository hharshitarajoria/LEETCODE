class Solution {
public:
    int count(vector<int>& nums, int k){
        int n = nums.size();
        int l=0,r=0,sum=0,cnt=0;
        while(r<n){
            sum += (nums[r]%2);
            while(sum>k){
                sum = sum - (nums[l]%2);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k) - count(nums,k-1);
    }
};