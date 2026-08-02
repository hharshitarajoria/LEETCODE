class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int low=1, high=maxi;
        while(low<=high){
            int sum=0;
            int mid =(low+high)/2;
            for(int i=0;i<n;i++){
                sum+= ceil((double)nums[i]/(double)mid);
            }
            if(sum <= threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
         return low;
    }
};