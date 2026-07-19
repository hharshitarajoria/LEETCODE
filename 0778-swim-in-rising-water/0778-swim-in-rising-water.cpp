class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1);
        for( int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        rank.resize(n+1,0);
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]= findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]< size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<pair<int,int>> pos(n*n);
        DisjointSet ds(n*n);

        //store positions
        for( int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pos[grid[i][j]] = {i,j};
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for( int time=0 ;time<n*n ;time++){
            int row = pos[time].first;
            int col= pos[time].second;
            
            for(int i=0;i<4;i++){
                int nrow = row+ dr[i];
                int ncol = col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                    if(grid[nrow][ncol] <=time){
                        int nodeNo= row*n+col;
                        int adjNodeNo= nrow*n+ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
            if(ds.findUPar(0) == ds.findUPar(n*n-1)){
                return time;
            }
        }
        return -1;
    }
};