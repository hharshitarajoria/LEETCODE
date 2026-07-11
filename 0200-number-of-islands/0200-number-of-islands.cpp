class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,-1,0,+1};
        int island=0;
        for( int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]== '1'){
                    island++;
                    q.push({i,j});
                    vis[i][j]=1;
                    
                    while(!q.empty()){
                        int row= q.front().first;
                        int col= q.front().second;
                        q.pop();
                        for( int i=0;i<4;i++){
                            int nrow= row+ delRow[i];
                            int ncol = col+ delCol[i];
                            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m
                               && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
        return island;
    }
};