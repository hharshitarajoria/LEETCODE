class Solution {
public:
    bool allocatePossible(vector<int> &nums, int limit, int k){
        int n= nums.size();
        int subarraySum=0 ; int allocated=1;
        for(int i=0;i<n;i++){
            if(nums[i]>limit){
                return false;
            }
            if( subarraySum +nums[i] > limit){
                allocated++;
                subarraySum = nums[i];
            }
            else{
                subarraySum +=nums[i];
            }
            if(allocated > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int sum=0;
        int n = nums.size();
        if(k>n) return -1;
        int ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(allocatePossible(nums,mid,k)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low; // return ans;
    }
};