class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=  matrix.size();
        int n=  matrix[0].size();
        for(int i=0;i<m;i++){
            int low=0, high=n-1;
            while(low<=high){
                int mid= (low+high)/2;
                if(matrix[i][mid]==target) return true;
                if(matrix[i][mid] > target) high=mid-1;
                else low=mid+1;
            }
         }
         return false;
    }
};