class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2= nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            int idx=-1;
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    idx=j;
                    break; 
                }       
            }
            int next = -1;
            for(int j = idx + 1; j < nums2.size(); j++) {
                if(nums2[j] > nums1[i]) {
                    next = nums2[j];
                    break;
                }
            }
            ans.push_back(next);
        }
        return ans;
    }
};