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
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n);
        //connect 1s
        for( int row=0; row<n ;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                // go to neighbors
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int ind=0;ind<4;ind++){
                    int nrow= row+dr[ind];
                    int ncol= col+dc[ind];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                        if(grid[nrow][ncol]==1){
                        int nodeNo = row*n+col;
                        int adjNodeNo = nrow*n+ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        //for each 0 calculate size
        int mx=0;
        for( int row=0; row<n ;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                // go to neighbors
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int nrow= row+dr[ind];
                    int ncol= col+dc[ind];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                        if(grid[nrow][ncol]==1){
                            components.insert(ds.findUPar(nrow *n + ncol)); // ultimate parents will be stored
                        }
                    }
                }
                int totalSize=0;
                for( auto it: components){
                    totalSize += ds.size[it];
                }
                mx = max(totalSize+1,mx);
            }
        }
        // if grid contain all 1s
        for( int cellNo=0; cellNo< n*n; cellNo++){
                mx = max(mx,ds.size[ds.findUPar(cellNo)]);
            }
        return mx;
    }
};