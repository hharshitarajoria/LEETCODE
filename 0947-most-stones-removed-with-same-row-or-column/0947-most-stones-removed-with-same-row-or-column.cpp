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
        if(node == parent[node]) return node;
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
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        // need dimensions of grid
        int maxRow=0;
        int maxCol=0;
        for(auto it: stones){
            maxRow= max(maxRow, it[0]);
            maxCol= max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map <int,int> stoneNode;
        //to find stone node
        for(auto it: stones){
            int srow= it[0];
            int scol = it[1]+maxRow+1;
            ds.unionBySize(srow,scol);
            stoneNode[srow]=1;
            stoneNode[scol]=1;
        }
        int cnt=0;
        for(auto it: stoneNode){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }
     return n- cnt;
    }
};