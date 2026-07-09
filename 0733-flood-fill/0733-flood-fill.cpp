class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color,int initialColor, 
              vector<vector<int>>& ans,int delRow[], int delCol[]){
        ans[row][col] = color;
        int n= image.size();
        int m=image[0].size();

        for( int i=0;i<4;i++){
            int nrow= row+delRow[i];
            int ncol = col+delCol[i];

            if(nrow>=0 && nrow<n && ncol >=0 && ncol<m
                && image[nrow][ncol] == initialColor && ans[nrow][ncol] != color ){
                    dfs(image,nrow,ncol,color,initialColor,ans,delRow,delCol);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans= image;
        int delRow[]= {-1,0,+1,0};
        int delCol[] ={0,+1,0,-1};
        dfs(image,sr,sc,color,initialColor,ans,delRow,delCol);
        return ans;
    }
};