class Solution {
public:
    int maxElem(vector<vector<int>>& mat, int m, int n,int row){
        int maxInd=-1;
        int maxVal=-1;
        for(int i=0; i<n ;i++){
            if(mat[row][i] > maxVal){
                maxVal= mat[row][i];
                maxInd= i;
            }
        }
        return maxInd;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n= mat[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int col= maxElem(mat,m,n,mid);
            int top = mid-1>=0 ? mat[mid-1][col] : -1; //in bound? yes :no
            int down = mid+1 <m ? mat[mid+1][col] : -1; //in bound? yes :no
            if(mat[mid][col]> top && mat[mid][col]>down){
                return{mid,col};
            }
            else if(mat[mid][col] < down) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};