class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
        if(mpp[nums[i]]==1) return nums[i];
        }
        return -1;
    }
};