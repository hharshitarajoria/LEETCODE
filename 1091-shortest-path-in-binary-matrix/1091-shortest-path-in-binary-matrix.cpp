class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
         // Source or destination blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        // Single cell matrix
        if (n == 1) {
            return 1;
        }
        // int src= grid[0][0];
        // int dest= grid[n-1][n-1];
        pair<int, int> src = {0, 0};
        pair<int, int> dest = {n - 1, n - 1};
        queue<pair<int,pair<int,int>>> q; //{dist,{r,c}}
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[src.first][src.second]=1;
        q.push({1,{src.first,src.second}});
        while(!q.empty()){
            int row= q.front().second.first;
            int col= q.front().second.second;
            int dis=q.front().first;
            q.pop();

            for( int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int newr= row+ dr;
                    int newc= col+dc;
                    if(newr>=0 && newr<n && newc>=0 && newc<n
                        && grid[newr][newc]==0 && dis+1< dist[newr][newc] ){
                            dist[newr][newc]= dis+1;
                            //if ans
                            if(newr==dest.first && newc==dest.second) return dis+1;
                            q.push({1+dis, {newr,newc}});
                        }
                }
            }
        }
        return -1;
    }
};