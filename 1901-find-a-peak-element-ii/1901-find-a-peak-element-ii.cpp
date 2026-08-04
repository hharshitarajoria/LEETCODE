class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int delRow[]={0,-1,1,0};
        int delCol[]={1,0,0,-1};
        int n= mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool peak=true;
                for(int k=0;k<4;k++){
                    int nrow= i+delRow[k];
                    int ncol= j+delCol[k];
                    if(nrow>=0 && ncol>=0 
                          && nrow<m &&ncol<n){
                            if( mat[nrow][ncol]>= mat[i][j] ){
                               peak=false;
                               break;
                        }
                    }
                }
                if(peak) return {i,j};
            }
        }
        return {-1,-1};
    }
};